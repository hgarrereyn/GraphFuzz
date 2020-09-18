
#include "graph.hpp"

#include <gtest/gtest.h>


TEST(graph, fillTerminal) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "dat *", "id": 0}
            ],
            "scopes": [
                { "name": "init_dat", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "consume_dat", "inputs": [0], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
    TGraph graph(schema);

    graph.AddNode(schema.GetScope(0), 0);
    graph.FillTerminal();

    Node n = graph.g.nodes(1);

    ASSERT_EQ(n.index(), 1);
    ASSERT_EQ(n.type(), 1);
    ASSERT_EQ(n.in_ref(0).node_idx(), 0);
    ASSERT_EQ(n.in_ref(0).conn_idx(), 0);
}

TEST(graph, fillMultiTerminal) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1},
                {"name": "c", "id": 2},
                {"name": "d", "id": 3}
            ],
            "scopes": [
                { "name": "multi", "inputs": [0,1], "outputs": [2,3], "context": 0 },
                { "name": "init_a", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "consume_a", "inputs": [0], "outputs": [], "context": 0 },
                { "name": "init_b", "inputs": [], "outputs": [1], "context": 0 },
                { "name": "consume_b", "inputs": [1], "outputs": [], "context": 0 },
                { "name": "init_c", "inputs": [], "outputs": [2], "context": 0 },
                { "name": "consume_c", "inputs": [2], "outputs": [], "context": 0 },
                { "name": "init_d", "inputs": [], "outputs": [3], "context": 0 },
                { "name": "consume_d", "inputs": [3], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
    TGraph graph(schema);

    graph.AddNode(schema.GetScope(0), 0);
    graph.FillTerminal();

    Node multi = graph.g.nodes(0);

    Node a = graph.g.nodes(multi.in_ref(0).node_idx());
    ASSERT_EQ(a.type(), 1);
    ASSERT_EQ(a.out_ref(0).node_idx(), 0);
    ASSERT_EQ(a.out_ref(0).conn_idx(), 0);

    Node b = graph.g.nodes(multi.in_ref(1).node_idx());
    ASSERT_EQ(b.type(), 3);
    ASSERT_EQ(b.out_ref(0).node_idx(), 0);
    ASSERT_EQ(b.out_ref(0).conn_idx(), 1);

    Node c = graph.g.nodes(multi.out_ref(0).node_idx());
    ASSERT_EQ(c.type(), 6);
    ASSERT_EQ(c.in_ref(0).node_idx(), 0);
    ASSERT_EQ(c.in_ref(0).conn_idx(), 0);

    Node d = graph.g.nodes(multi.out_ref(1).node_idx());
    ASSERT_EQ(d.type(), 8);
    ASSERT_EQ(d.in_ref(0).node_idx(), 0);
    ASSERT_EQ(d.in_ref(0).conn_idx(), 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
