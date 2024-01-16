
#include <algorithm>
#include <fstream>
#include <iostream>
#include <setjmp.h>
#include <signal.h>
#include <sstream>
#include <stdint.h>
#include <stdlib.h>
#include <tuple>
#include <unordered_set>
#include <vector>

#ifdef TEST
#include <gtest/gtest.h>
#endif

#include <google/protobuf/text_format.h>
#include <google/protobuf/repeated_field.h>
#include "graph.pb.h"

#include "schema.hpp"


extern "C" size_t LLVMFuzzerMutate(char *data, int size, int max_size);


// Represents an open scope connection.
struct NodeLink {
    int node_idx;   /* Index of the current node in the graph. */
    bool forward;   /* True if this is a forward connection. */
    int conn_idx;   /* Connection index in the node. */
    int type;       /* Type of the connection. */
    int layer;      /* Layer of the existing node (used for filtering). */
};


class TGraph {
private:
    Schema *schema;
    Graph g;

    // Define tests that can access private methods.
    #ifdef TEST
    FRIEND_TEST(graph, fillTerminal);
    FRIEND_TEST(graph, fillMultiTerminal);
    #endif

    /**
     * Adds a new node to the graph tree without linking it.
     * 
     * Returns the node index.
     */
    int AddNode(ScopeDef scope, unsigned int layer) {
        auto index = g.nodes_size();

        Node *n = g.add_nodes();
        ResetNode(n, scope);
        n->set_index(index);
        n->set_layer(layer);

        return index;
    }

    /**
     * Reset a node in-place. This method doesn't change the layer.
     */
    void ResetNode(Node *n, ScopeDef scope) {
        n->set_type(scope.type);
        n->clear_in_ref();
        n->clear_out_ref();

        for (unsigned long i = 0; i < scope.in_ref.size(); ++i) {
            NodeRef *r = n->add_in_ref();
            r->set_node_idx(-1);
        }
            
        for (unsigned long i = 0; i < scope.out_ref.size(); ++i) {
            NodeRef *r = n->add_out_ref();
            r->set_node_idx(-1);
        }

        if (scope.context_size > 0) {
            n->set_context(std::string(scope.context_size, '\x00'));
        }
    }

    /**
     * Returns a vector of NodeLink's containing open connections in the
     * current graph.
     */
    std::vector<NodeLink> GetOpenLinks() {
        std::vector<NodeLink> open;

        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            Node n = g.nodes(i);
            ScopeDef scope = schema->GetScope(n.type());

            for (size_t j = 0; j < scope.in_ref.size(); ++j)
                if ((int)n.in_ref((int)j).node_idx() == -1)
                    open.push_back(
                        {(int)i, false, (int)j, (int)scope.in_ref[j], n.layer()});
            
            for (size_t j = 0; j < scope.out_ref.size(); ++j)
                if ((int)n.out_ref((int)j).node_idx() == -1)
                    open.push_back(
                        {(int)i, true, (int)j, (int)scope.out_ref[j], n.layer()});
        }

        return open;
    }

    std::vector<NodeLink> GetAllLinks() {
        std::vector<NodeLink> links;

        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            Node n = g.nodes(i);
            ScopeDef scope = schema->GetScope(n.type());

            for (size_t j = 0; j < scope.in_ref.size(); ++j)
                links.push_back(
                    {(int)i, false, (int)j, (int)scope.in_ref[j], n.layer()});
            
            for (size_t j = 0; j < scope.out_ref.size(); ++j)
                links.push_back(
                    {(int)i, true, (int)j, (int)scope.out_ref[j], n.layer()});
        }

        return links;
    }

    /**
     * Link node A to node B. A->B is always a forward connection.
     */
    void Link(int node_a, int conn_a, int node_b, int conn_b) {
        NodeRef *ra = g.mutable_nodes(node_a)->mutable_out_ref(conn_a);
        ra->set_node_idx(node_b);
        ra->set_conn_idx(conn_b);

        NodeRef *rb = g.mutable_nodes(node_b)->mutable_in_ref(conn_b);
        rb->set_node_idx(node_a);
        rb->set_conn_idx(conn_a);
    }

    /**
     * Unlink node A from its forward connection.
     */
    void Unlink(int node_a, int conn_a) {
        NodeRef *ra = g.mutable_nodes(node_a)->mutable_out_ref(conn_a);
        auto node_b = ra->node_idx();
        auto conn_b = ra->conn_idx();
        ra->set_node_idx(-1);

        NodeRef *rb = g.mutable_nodes(node_b)->mutable_in_ref(conn_b);
        rb->set_node_idx(-1);
    }

    /**
     * Unlink Node b from its backward connection.
     */
    void UnlinkBackward(int node_b, int conn_b) {
        NodeRef *rb = g.mutable_nodes(node_b)->mutable_in_ref(conn_b);
        auto node_a = rb->node_idx();
        auto conn_a = rb->conn_idx();
        rb->set_node_idx(-1);

        NodeRef *ra = g.mutable_nodes(node_a)->mutable_out_ref(conn_a);
        ra->set_node_idx(-1);
    }

    /**
     * DFS on the graph structure in both directions. Visited nodes are added
     * to an unordered set.
     */
    void Visit(std::unordered_set<int> *seen, int idx) {
        if (idx == -1 || seen->count(idx)) return;
        seen->insert(idx);

        for (int i = 0; i < g.nodes(idx).in_ref_size(); ++i)
            Visit(seen, g.nodes(idx).in_ref(i).node_idx());

        for (int i = 0; i < g.nodes(idx).out_ref_size(); ++i)
            Visit(seen, g.nodes(idx).out_ref(i).node_idx());
    }

    /**
     * Reindex node n with a new index.
     * 
     * This method also updates neighbors of node n.
     */
    void ReindexNode(Node *n, int new_idx) {
        n->set_index(new_idx);

        for (int i = 0; i < n->in_ref_size(); ++i) {
            NodeRef r = n->in_ref(i);
            if (r.node_idx() == -1) continue;
            g.mutable_nodes(r.node_idx())->mutable_out_ref(r.conn_idx())->set_node_idx(new_idx);
        }

        for (int i = 0; i < n->out_ref_size(); ++i) {
            NodeRef r = n->out_ref(i);
            if (r.node_idx() == -1) continue;
            g.mutable_nodes(r.node_idx())->mutable_in_ref(r.conn_idx())->set_node_idx(new_idx);
        }
    }

    /**
     * Offset all node indexes and layers by a fixed amount to prepare for merging.
     */
    void ApplyOffset(int idx_offset, int layer_offset) {
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            Node *n = g.mutable_nodes(i);
            n->set_index(n->index() + idx_offset);
            n->set_layer(n->layer() + layer_offset);

            for (unsigned int j = 0; j < n->in_ref_size(); ++j) {
                NodeRef *r = n->mutable_in_ref(j);
                if (r->node_idx() == -1) continue;
                r->set_node_idx(r->node_idx() + idx_offset);
            }

            for (unsigned int j = 0; j < n->out_ref_size(); ++j) {
                NodeRef *r = n->mutable_out_ref(j);
                if (r->node_idx() == -1) continue;
                r->set_node_idx(r->node_idx() + idx_offset);
            }
        }
    }

    /**
     * Remove all nodes not in keep.
     */
    void Collapse(std::unordered_set<int> keep) {
        google::protobuf::RepeatedPtrField<Node> *nodes = g.mutable_nodes();
        
        unsigned int write_idx = 0;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            if (keep.count(i)) {
                if (i != write_idx) {
                    ReindexNode(g.mutable_nodes(i), write_idx);
                    nodes->SwapElements(i, write_idx);
                }
                write_idx += 1;
            }
        }

        // Delete unused elements from the end.
        nodes->DeleteSubrange(write_idx, g.nodes_size() - write_idx);
    }

    /**
     * Append a node to the current graph.
     */
    void AppendNode(const Node &n2) {
        Node *n = g.add_nodes();
        n->set_type(n2.type());
        n->set_layer(n2.layer());
        n->set_index(n2.index());
        n->set_context(n2.context());

        for (unsigned long i = 0; i < n2.in_ref_size(); ++i) {
            NodeRef *r = n->add_in_ref();
            r->set_node_idx(n2.in_ref(i).node_idx());
            r->set_conn_idx(n2.in_ref(i).conn_idx());
        }

        for (unsigned long i = 0; i < n2.out_ref_size(); ++i) {
            NodeRef *r = n->add_out_ref();
            r->set_node_idx(n2.out_ref(i).node_idx());
            r->set_conn_idx(n2.out_ref(i).conn_idx());
        }
    }

    /**
     * Copy another graph into this one.
     */
    void CopyOther(TGraph other) {
        // Reindex all other nodes.
        unsigned int g1_size = (unsigned int)g.nodes_size();
        int g1_max_layer = g.nodes(0).layer();
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            if (g.nodes(i).layer() > g1_max_layer) {
                g1_max_layer = g.nodes(i).layer();
            }
        }
        other.ApplyOffset(g1_size, g1_max_layer);

        // Copy nodes.
        for (unsigned int i = 0; i < (unsigned int)other.g.nodes_size(); ++i) {
            AppendNode(other.g.nodes(i));
        }
    }

    /**
     * Normalize layer numbering to prevent integer overflows.
     */
    void SimplifyLayers() {
        // Generate a sorted ordering.
        std::vector<Node *> nodes;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            nodes.push_back(g.mutable_nodes(i));
        }

        std::sort(nodes.begin(), nodes.end(), [](auto *lhs, auto *rhs) {
            if (lhs->layer() == rhs->layer()) {
                return lhs->index() < rhs->index();
            } else {
                return lhs->layer() < rhs->layer();
            }
        });

        // Iterate and assign new layers.
        int new_layer = 0;
        int curr_layer = nodes[0]->layer();

        for (unsigned int i = 0; i < nodes.size(); ++i) {
            if (nodes[i]->layer() != curr_layer) {
                curr_layer = nodes[i]->layer();
                new_layer += 1;
                nodes[i]->set_layer(new_layer);
            } else {
                nodes[i]->set_layer(new_layer);
            }
        }
    }

    /**
     * Set the layer of a node and ripple this layer across the graph.
     */
    void ResetLayers(unsigned int node_idx, int layer) {
        g.mutable_nodes(node_idx)->set_layer(layer);

        for (int i = 0; i < g.nodes(node_idx).in_ref_size(); ++i) {
            unsigned other_idx = g.nodes(node_idx).in_ref(i).node_idx();
            if (other_idx == -1 || g.nodes(other_idx).layer() < layer) continue;
            ResetLayers(other_idx, layer - 1);
        }

        for (int i = 0; i < g.nodes(node_idx).out_ref_size(); ++i) {
            unsigned other_idx = g.nodes(node_idx).out_ref(i).node_idx();
            if (other_idx == -1 || g.nodes(other_idx).layer() > layer) continue;
            ResetLayers(other_idx, layer + 1);
        }
    }

    /**
     * Recursively sample and append nodes from a type tree.
     */
    void AppendTree(unsigned int node_idx, unsigned int conn_idx, int layer, bool forward, TypeTree tree) {
        // fail loud when assertions are enabled
        assert(tree.num_subtrees > 0);
        assert(tree.children.size() > 0);
        // return early in case the assertions are disabled
        if (tree.num_subtrees == 0 || tree.children.size() == 0) return;

        unsigned int sample = ((unsigned int)rand()) % tree.num_subtrees;
        unsigned int sample_idx = 0;
        unsigned int subtree_sum = tree.children[sample_idx].num_subtrees;
        while (subtree_sum < sample && sample_idx < tree.children.size()) {
            sample_idx += 1;
            subtree_sum += tree.children[sample_idx].num_subtrees;
        }

        ScopeTree stree = tree.children[sample_idx];
        ScopeDef root_def = schema->SampleSignatureIndex(stree.sig_idx);

        int next_layer = forward ? layer + 1 : layer - 1;
        int rev_layer = forward ? layer - 1 : layer + 1;

        unsigned int root = AddNode(root_def, next_layer);

        if (forward) {
            Link(node_idx, conn_idx, root, stree.conn_idx);
        } else {
            Link(root, stree.conn_idx, node_idx, conn_idx);
        }

        // Recurse through forward children.
        for (unsigned int i = 0; i < stree.children.size(); ++i) {
            AppendTree(root, i, next_layer, forward, stree.children[i]);
        }

        // Recurse through reverse children.
        for (unsigned int i = 0; i < stree.rev_children.size(); ++i) {
            unsigned int rev_conn_idx = i < stree.conn_idx ? i : i + 1;
            AppendTree(root, rev_conn_idx, rev_layer, !forward, stree.rev_children[i]);
        }
    }

    /**
     * Fill one connection with a finalizer or initializer.
     */
    void FillOneTerminal(NodeLink n) {
        TypeTree tree = (n.forward ? schema->GetFinalizer(n.type) 
                                   : schema->GetInitializer(n.type));
        AppendTree(n.node_idx, n.conn_idx, n.layer, n.forward, tree);
    }

    /**
     * Fill open connections with terminal nodes.
     */
    void FillTerminal() {
        auto open = GetOpenLinks();

        for (size_t i = 0; i < open.size(); ++i) {
            NodeLink n = open[i];
            FillOneTerminal(n);
        }
    }

    /**
     * Mutate the graph by invoking LLVMFuzzerMutate on a node's context.
     */
    bool MutateContext() {
        std::vector<int> with_context;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            if (g.nodes(i).context().size() > 0) {
                with_context.push_back(i);
            }
        }

        if (with_context.size() == 0) return false;

        int node_idx = with_context[rand() % with_context.size()];
        std::string *s = g.mutable_nodes(node_idx)->mutable_context();

        if (s == nullptr) {
            return false;
        }

        LLVMFuzzerMutate((char *)&(*s)[0], (int)s->size(), (int)s->size());

        return true;
    }

    /**
     * Mutate by replacing a destructor scope with a random consumer scope.
     */
    void MutateExtendDestructor() {
        std::vector<unsigned int> destructors;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            if (schema->IsDestructor(g.nodes(i).type())) {
                destructors.push_back(i);
            }
        }

        if (destructors.size() == 0) return;

        // Select a random destructor.
        auto target_idx = destructors[rand() % destructors.size()];

        // Unlink the destructor.
        NodeRef r = g.nodes(target_idx).in_ref(0);
        unsigned int parent_idx = r.node_idx();
        unsigned int parent_conn = r.conn_idx();
        Unlink(parent_idx, parent_conn);

        // Pick a new consumer.
        ScopeDef scope = schema->GetScope(g.nodes(target_idx).type());
        unsigned int ref_type = scope.in_ref[0];

        ScopeDef consumer;
        unsigned int consumer_conn_idx;
        std::tie(consumer, consumer_conn_idx) = schema->GetRandomConsumer(ref_type);

        // Replace the node.
        Node *n = g.mutable_nodes(target_idx);
        ResetNode(n, consumer);

        // Re-link.
        Link(parent_idx, parent_conn, target_idx, consumer_conn_idx);

        // Fill remaining spots.
        FillTerminal();
    }

    /**
     * Mutate by replacing a constructor scope with a random producer scope.
     */
    void MutateExtendConstructor() {
        std::vector<unsigned int> constructors;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            if (schema->IsConstructor(g.nodes(i).type())) {
                constructors.push_back(i);
            }
        }

        if (constructors.size() == 0) return;

        // Select a random constructor.
        auto target_idx = constructors[rand() % constructors.size()];

        // Unlink the constructor.
        NodeRef r = g.nodes(target_idx).out_ref(0);
        unsigned int parent_idx = r.node_idx();
        unsigned int parent_conn = r.conn_idx();
        Unlink(target_idx, 0);

        // Pick a new producer.
        ScopeDef scope = schema->GetScope(g.nodes(target_idx).type());
        unsigned int ref_type = scope.out_ref[0];

        ScopeDef producer;
        unsigned int producer_conn_idx;
        std::tie(producer, producer_conn_idx) = schema->GetRandomProducer(ref_type);

        // Replace the node.
        Node *n = g.mutable_nodes(target_idx);
        ResetNode(n, producer);

        // Re-link.
        Link(target_idx, producer_conn_idx, parent_idx, parent_conn);

        // Fill remaining spots.
        FillTerminal();
    }

    /**
     * Mutate by cross-linking two nodes.
     *
     * If a non-zero split is provided, the producer node index will be strictly
     * less than split and the consumer node index will be greater than split.
     * This mechanism is used when crosslinking two different graphs.
     */
    void MutateCrosslink(unsigned int split=0) {
        assert(split <= g.nodes_size());

        // Early check.
        if (g.nodes_size() <= 2) {
            return;
        }

        // Generate a list of producers.
        // (node_idx, conn_idx, ref_type)
        std::vector<std::tuple<unsigned int, unsigned int, unsigned int>> producers;
        unsigned int producer_limit = split == 0 ? (unsigned int)g.nodes_size() : split;
        for (unsigned int i = 0; i < producer_limit; ++i) {
            ScopeDef scope = schema->GetScope(g.nodes(i).type());
            for (unsigned int j = 0; j < scope.out_ref.size(); ++j) {
                producers.push_back(std::make_tuple(i, j, scope.out_ref[j]));
            }
        }

        if (producers.size() == 0) return;

        unsigned int start_node;
        unsigned int start_conn;
        unsigned int start_type;
        std::tie(start_node, start_conn, start_type) = producers[rand() % producers.size()];

        NodeRef start_ref = g.nodes(start_node).out_ref(start_conn);
        unsigned int avoid_node = start_ref.node_idx();
        unsigned int avoid_conn = start_ref.conn_idx();

        int start_layer = g.nodes(start_node).layer();

        // Generate a list of consumers with specified type.
        // (node_idx, conn_idx)
        std::vector<std::tuple<unsigned int, unsigned int>> consumers;
        for (unsigned int i = split; i < (unsigned int)g.nodes_size(); ++i) {
            if (g.nodes(i).layer() <= start_layer) continue;

            ScopeDef scope = schema->GetScope(g.nodes(i).type());
            for (unsigned int j = 0; j < scope.in_ref.size(); ++j) {
                if (i == avoid_node && j == avoid_conn) continue;

                if (scope.in_ref[j] == start_type) {
                    consumers.push_back(std::make_tuple(i, j));
                }
            }
        }

        if (consumers.size() == 0) return;

        unsigned int end_node;
        unsigned int end_conn;
        std::tie(end_node, end_conn) = consumers[rand() % consumers.size()];

        // Unlink nodes.
        Unlink(start_node, start_conn);
        UnlinkBackward(end_node, end_conn);

        // Re-link.
        Link(start_node, start_conn, end_node, end_conn);

        // Remove orphaned nodes.
        std::unordered_set<int> component;
        Visit(&component, start_node);
        Collapse(component);

        FillTerminal();
    }

    /**
     * Mutate by replacing a consumer scope with a destructor.
     */
    void MutateTruncateDestructor() {
        // Generate a list of producers.
        // (node_idx, conn_idx)
        std::vector<std::tuple<unsigned int, unsigned int, unsigned int>> producers;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            ScopeDef scope = schema->GetScope(g.nodes(i).type());
            for (unsigned int j = 0; j < scope.out_ref.size(); ++j) {
                producers.push_back(std::make_tuple(i, j, scope.out_ref[j]));
            }
        }

        if (producers.size() == 0) return;

        // Select a random producer.
        unsigned int start_node;
        unsigned int start_conn;
        unsigned int start_type;
        std::tie(start_node, start_conn, start_type) = producers[rand() % producers.size()];

        // Unlink target node.
        Unlink(start_node, start_conn);

        // Remove orphaned nodes.
        std::unordered_set<int> component;
        Visit(&component, start_node);
        Collapse(component);

        FillTerminal();
    }

    /**
     * Mutate by replacing a producer scope with a constructor.
     */
    void MutateTruncateConstructor() {
        // Generate a list of consumers.
        // (node_idx, conn_idx)
        std::vector<std::tuple<unsigned int, unsigned int, unsigned int>> consumers;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            ScopeDef scope = schema->GetScope(g.nodes(i).type());
            for (unsigned int j = 0; j < scope.in_ref.size(); ++j) {
                consumers.push_back(std::make_tuple(i, j, scope.in_ref[j]));
            }
        }

        if (consumers.size() == 0) return;

        // Select a random producer.
        unsigned int end_node;
        unsigned int end_conn;
        unsigned int end_type;
        std::tie(end_node, end_conn, end_type) = consumers[rand() % consumers.size()];

        // Unlink target node.
        UnlinkBackward(end_node, end_conn);

        // Remove orphaned nodes.
        std::unordered_set<int> component;
        Visit(&component, end_node);
        Collapse(component);

        FillTerminal();
    }

    /**
     * Replace an endpoint with one that has the same signature.
     */
    void MutateSwapEquivalent() {
        unsigned int idx_a = rand() % g.nodes_size();

        ScopeDef def = schema->GetScope(g.nodes(idx_a).type());
        ScopeDef other = schema->WithMatchingSignature(def);

        if (def.type == other.type) return;

        g.mutable_nodes(idx_a)->set_type(other.type);
        
        std::string new_context(other.context_size, '\x00');
        g.mutable_nodes(idx_a)->set_context(new_context);
    }

    /**
     * Swap the index of two nodes on the same layer.
     */
    void MutateLayerIndex() {
        // Get a random node.
        unsigned int idx_a = rand() % g.nodes_size();
        int layer_a = g.nodes(idx_a).layer();

        // Find other nodes with the same layer.
        std::vector<unsigned int> other;
        for (unsigned int i = 0; i < g.nodes_size(); ++i) {
            if (i == idx_a || g.nodes(i).layer() != layer_a) continue;
            other.push_back(i);
        }

        if (other.size() == 0) return;

        unsigned int idx_b = other[rand() % other.size()];

        // Swap indexes
        ReindexNode(g.mutable_nodes(idx_a), idx_b);
        ReindexNode(g.mutable_nodes(idx_b), idx_a);
        g.mutable_nodes()->SwapElements(idx_a, idx_b);
    }

    /**
     * Given edge A->A, splice in an endpoint with signature Ax...->Ax...
     * (i.e. this usually adds a method call)
     */
    void MutateSpliceIn() {
        // Generate a list of producers.
        // (node_idx, conn_idx)
        std::vector<std::tuple<unsigned int, unsigned int, unsigned int>> producers;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            ScopeDef scope = schema->GetScope(g.nodes(i).type());
            for (unsigned int j = 0; j < scope.out_ref.size(); ++j) {
                producers.push_back(std::make_tuple(i, j, scope.out_ref[j]));
            }
        }

        if (producers.size() == 0) return;

        // Select a random producer.
        unsigned int start_node;
        unsigned int start_conn;
        unsigned int start_type;
        std::tie(start_node, start_conn, start_type) = producers[rand() % producers.size()];

        // Find a scope to splice in.
        if (!schema->HasUser(start_type)) return;

        ScopeDef def;
        unsigned int in_idx;
        unsigned int out_idx;
        std::tie(def, in_idx, out_idx) = schema->GetRandomUser(start_type);

        int new_idx = AddNode(def, g.nodes(start_node).layer() + 1);

        // Unlink old connection.
        int back_node_idx = g.nodes(start_node).out_ref(start_conn).node_idx();
        int back_node_conn = g.nodes(start_node).out_ref(start_conn).conn_idx();
        Unlink(start_node, start_conn);

        // Add new connection
        Link(start_node, start_conn, new_idx, in_idx);
        Link(new_idx, out_idx, back_node_idx, back_node_conn);

        ResetLayers(new_idx, 0);

        FillTerminal();
    }

    /**
     * Given A->A->A, remove the middle scope.
     */
    void MutateSpliceOut() {
        std::vector<unsigned int> removable;
        for (int i = 0; i < g.nodes_size(); ++i) {
            if (schema->IsSpliceable(g.nodes(i).type())) {
                removable.push_back(i);
            }
        }

        if (removable.size() == 0) return;

        unsigned int node_idx = removable[rand() % removable.size()];

        unsigned int type;
        unsigned int in_idx;
        unsigned int out_idx;
        std::tie(type, in_idx, out_idx) = schema->GetRandomSplicePath(g.nodes(node_idx).type());

        // Unlink the middle node
        unsigned int prev_node = g.nodes(node_idx).in_ref(in_idx).node_idx();
        unsigned int prev_conn = g.nodes(node_idx).in_ref(in_idx).conn_idx();
        unsigned int next_node = g.nodes(node_idx).out_ref(out_idx).node_idx();
        unsigned int next_conn = g.nodes(node_idx).out_ref(out_idx).conn_idx();

        Unlink(node_idx, out_idx);
        Unlink(prev_node, prev_conn);
        Link(prev_node, prev_conn, next_node, next_conn);

        // Remove orphaned nodes.
        std::unordered_set<int> component;
        Visit(&component, prev_node);
        Collapse(component);

        FillTerminal();
    }

    /**
     * Perform a crossover mutation.
     *
     * Returns false if crossover is not possible.
     */
    bool MutateCross(TGraph other) {
        unsigned int g1_size = (unsigned int)g.nodes_size();

        // Copy other graph into this.
        CopyOther(other);

        MutateCrosslink(g1_size);

        SimplifyLayers();

        return true;
    }

public:
    TGraph(Schema *schema) : schema(schema) {}

    /**
     * Create a new graph from a seed with an upper bound on the node count.
     */
    bool Create(unsigned int seed, unsigned int max_nodes) {
        srand(seed);
        ScopeDef init = schema->GetRandomScope();
        return CreateWithScope(init);
    }

    bool CreateWithScope(ScopeDef def) {
        g = Graph();
        AddNode(def, 0);
        FillTerminal();

        return true;
    }

    bool Mutate(unsigned int seed, unsigned int max_nodes, float context_mutation_prob, int *mut_id) {
        srand(seed);

        if (((float)rand() / (float)RAND_MAX) < context_mutation_prob) {
            MutateContext();
            *mut_id = -1;
        } else {
            unsigned int mut_choice = rand() % 9;
            *mut_id = mut_choice;

            switch (mut_choice) {
                case 0: MutateCrosslink(); break;
                case 1: MutateTruncateDestructor(); break;
                case 2: MutateTruncateConstructor(); break;
                case 3: MutateLayerIndex(); break;
                case 4: MutateSwapEquivalent(); break;
                case 5: MutateExtendDestructor(); break;
                case 6: MutateExtendConstructor(); break;
                case 7: MutateSpliceIn(); break;
                case 8: MutateSpliceOut(); break;
            }

            // Remove orphaned nodes.
            std::unordered_set<int> component;
            Visit(&component, 0);
            Collapse(component);
        }

        return true;
    }

    bool Cross(TGraph other, unsigned int seed, unsigned int max_nodes) {
        srand(seed);
        MutateCross(other);

        // Remove orphaned nodes.
        std::unordered_set<int> component;
        Visit(&component, 0);
        Collapse(component);

        return true;
    }

    void Complete() {
        this->FillTerminal();
    }

    void PrintNode(Node n) {
        ScopeDef scope = schema->GetScope(n.type());
        std::cerr << "(" << n.index() << ")<" << n.layer() << ">" << scope.name << "::";

        std::cerr << "(";
        for (int j = 0; j < n.in_ref_size(); ++j) {
            if (j > 0) std::cerr << ", ";
            std::cerr << n.in_ref(j).node_idx() << "[" << n.in_ref(j).conn_idx() << "]";
        }
        std::cerr << ")(";
        for (int j = 0; j < n.out_ref_size(); ++j) {
            if (j > 0) std::cerr << ", ";
            std::cerr << n.out_ref(j).node_idx() << "[" << n.out_ref(j).conn_idx() << "]";
        }

        std::cerr << ")" << std::endl;
    }

    void PrintAll() {
        std::cerr << "-----------" << std::endl;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            Node n = g.nodes(i);
            PrintNode(n);
        }
    }

    /**
     * Returns a vector of Node objects ordered by layer, ascending.
     */
    std::vector<Node> GetOrderedNodes() {
        std::vector<Node> nodes;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            nodes.push_back(g.nodes(i));
        }

        std::sort(nodes.begin(), nodes.end(), [](const auto &lhs, const auto &rhs) {
            if (lhs.layer() == rhs.layer()) {
                return lhs.index() < rhs.index();
            } else {
                return lhs.layer() < rhs.layer();
            }
        });

        return nodes;
    }

    std::string Write(bool *err) {
        std::string out;
        if (!g.SerializeToString(&out)) *err = true;
        return out;
    }

    bool Read(std::string inp) {
        return g.ParseFromString(inp);
    }

    bool Validate() {
        if (g.nodes_size() == 0) return false;
        for (unsigned int i = 0; i < (unsigned int)g.nodes_size(); ++i) {
            Node n = g.nodes(i);
            ScopeDef scope = schema->GetScope(n.type());

            if (scope.in_ref.size() != (unsigned long)n.in_ref_size()) return false;
            if (scope.out_ref.size() != (unsigned long)n.out_ref_size()) return false;
        }
        return true;
    }
};
