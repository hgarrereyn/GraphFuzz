
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
#include <unordered_map>
#include <vector>

#include "json.hpp"
using json = nlohmann::json;


/* Scope definition template. */
struct ScopeDef {
    std::string name;                   /* Scope name. */
    unsigned int type;                  /* Scope type (index). */
    std::vector<unsigned int> in_ref;   /* vector of input types. */
    std::vector<unsigned int> out_ref;  /* Vector of output types. */
    unsigned int context_size;          /* Context size in bytes. */
};

struct Signature {
    std::vector<unsigned int> in_ref;
    std::vector<unsigned int> out_ref;

    bool operator==(const Signature &p) const {
        if (in_ref.size() != p.in_ref.size() || out_ref.size() != p.out_ref.size()) {
            return false;
        }

        for (int i = 0; i < in_ref.size(); ++i) {
            if (in_ref[i] != p.in_ref[i]) {
                return false;
            }
        }

        for (int i = 0; i < out_ref.size(); ++i) {
            if (out_ref[i] != p.out_ref[i]) {
                return false;
            }
        }

        return true;
    }

    void DebugPrint() {
        printf("sig((");
        for (int i = 0; i < in_ref.size(); ++i) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", in_ref[i]);
        }
        printf(")::(");
        for (int i = 0; i < out_ref.size(); ++i) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", out_ref[i]);
        }
        printf("))\n");
    }
};

template <>
struct std::hash<Signature> {
    size_t operator()(const Signature& sig) const {
        return 0; //TODO
    }
};

ScopeDef MakeScopeDef(json scope, unsigned int index) {
    ScopeDef def;

    def.name = scope["name"];
    def.type = index; // Scope "type" is the implicit scope index.
    for (size_t i = 0; i < scope["inputs"].size(); ++i) {
        def.in_ref.push_back(scope["inputs"][i]);
    }
    for (size_t i = 0; i < scope["outputs"].size(); ++i) {
        def.out_ref.push_back(scope["outputs"][i]);
    }
    def.context_size = scope["context"];

    return def;
}

struct TypeTree;
struct ScopeTree;

json TypeTreeToJSON(TypeTree tree);
json ScopeTreeToJSON(ScopeTree tree);

TypeTree TypeTreeFromJSON(json tree);
ScopeTree ScopeTreeFromJSON(json tree);

struct ScopeTree {
    unsigned int num_subtrees;          /* Number of possible trees to construct from this node. */
    unsigned int sig_idx;               /* Signature index (into all_sigs vector). */
    std::vector<TypeTree> children;     /* Forward children. */
    unsigned int conn_idx;              /* Index of forward connection. */
    std::vector<TypeTree> rev_children; /* Remaining reverse children. */
};

struct TypeTree {
    unsigned int num_subtrees;
    unsigned int index;                 /* Type index. */
    std::vector<ScopeTree> children;
};

json ScopeTreeToJSON(ScopeTree ref) {
    json tree;
    tree["num_subtrees"] = ref.num_subtrees;
    tree["sig_idx"] = ref.sig_idx;
    tree["conn_idx"] = ref.conn_idx;
    for (int i = 0; i < ref.children.size(); ++i) {
        tree["children"].push_back(TypeTreeToJSON(ref.children[i]));
    }
    for (int i = 0; i < ref.rev_children.size(); ++i) {
        tree["rev_children"].push_back(TypeTreeToJSON(ref.rev_children[i]));
    }
    return tree;
}

json TypeTreeToJSON(TypeTree ref) {
    json tree;
    tree["num_subtrees"] = ref.num_subtrees;
    tree["index"] = ref.index;
    for (int i = 0; i < ref.children.size(); ++i) {
        tree["children"].push_back(ScopeTreeToJSON(ref.children[i]));
    }
    return tree;
}

TypeTree TypeTreeFromJSON(json ref) {
    TypeTree tree;
    tree.num_subtrees = ref["num_subtrees"];
    tree.index = ref["index"];
    for (int i = 0; i < ref["children"].size(); ++i) {
        tree.children.push_back(ScopeTreeFromJSON(ref["children"][i]));
    }
    return tree;
}

ScopeTree ScopeTreeFromJSON(json ref) {
    ScopeTree tree;
    tree.num_subtrees = ref["num_subtrees"];
    tree.sig_idx = ref["sig_idx"];
    tree.conn_idx = ref["conn_idx"];
    for (int i = 0; i < ref["children"].size(); ++i) {
        tree.children.push_back(TypeTreeFromJSON(ref["children"][i]));
    }
    for (int i = 0; i < ref["rev_children"].size(); ++i) {
        tree.rev_children.push_back(TypeTreeFromJSON(ref["rev_children"][i]));
    }
    return tree;
}


class Schema {
private:
    // Internal schema json.
    json _schema;

    // {type_id: type_idx}
    std::unordered_map<unsigned int, unsigned int> type_remap;

    std::unordered_map<unsigned int, TypeTree> initializers;
    std::unordered_map<unsigned int, TypeTree> finalizers;

    // type: [
    //     (scope, conn_idx),
    //     (scope, conn_idx),
    //     ...
    // ]
    std::unordered_map<unsigned int, std::vector<std::tuple<ScopeDef, unsigned int>>> consumers;
    std::unordered_map<unsigned int, std::vector<std::tuple<ScopeDef, unsigned int>>> producers;
    std::unordered_map<unsigned int, std::vector<std::tuple<ScopeDef, unsigned int, unsigned int>>> users;

    // scope_id: [(type, in_idx, out_idx)]
    std::unordered_map<unsigned int, std::vector<std::tuple<unsigned int, unsigned int, unsigned int>>> users_by_scope;

    // List of all scopes.
    std::vector<ScopeDef> scopes;

    // List of scopes with types that can be created/destroyed.
    std::vector<unsigned int> usable_scopes;
    std::unordered_map<unsigned int, std::vector<unsigned int>> usable_consumers;
    std::unordered_map<unsigned int, std::vector<unsigned int>> usable_producers;
    std::unordered_map<unsigned int, std::vector<unsigned int>> usable_users;

    std::vector<bool> is_constructor;
    std::vector<bool> is_destructor;

    // Cache calls to BuildTypeTree
    std::map<std::tuple<unsigned int, bool, std::vector<unsigned int>>, TypeTree> type_tree_cache;

    // Maps a Singature to a list of scope indexes with the same signature.
    std::unordered_map<Signature, std::vector<unsigned int>> sig_map;

    // A canonical list of signatures. Signature indexes can be used to reference elements
    // in this vector.
    std::vector<Signature> all_sigs;

    Schema(json schema): _schema(schema) {}
public:
    Schema() {}

    /** Load a JSON schema from a file. */
    static Schema *FromFile(std::string filename) {
        std::cerr << "[*] Loading: " << filename << std::endl;

        std::ifstream s_file;
        std::stringstream s_dat;
        s_file.open(filename);
        s_dat << s_file.rdbuf();
        s_file.close();
        auto s_str = s_dat.str();

        return Schema::FromString(s_str);
    }

    /** Load a JSON schema from a string */
    static Schema *FromString(std::string data) {
        json _schema = json::parse(data);
        return new Schema(_schema);
    }

    /**
     * Save pre-computed schema paths as json.
     * - initializers
     * - finalizers
     * 
     * {
     *   "initializers": {
     *     0: {
     *       "num_subtrees": 1,
     *       "index": 3,
     *       "children": [
     *         {
     *           "num_subtrees": 1,
     *           "sig_idx": 0,
     *           "children": [...],
     *           "conn_idx": 0,
     *           "rev_children": [...]
     *         },
     *         ...
     *       ]
     *     }
     *
     *   },
     *   "finalizers": {...}
     * }
     */
    void SaveCached(std::string filename) {
        json cache;

        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            cache["initializers"].push_back(TypeTreeToJSON(initializers[type_id]));
            cache["finalizers"].push_back(TypeTreeToJSON(finalizers[type_id]));
        }

        std::ofstream out(filename);
        out << cache << std::endl;
    }

    void LoadCached(std::string filename) {
        std::ifstream inp(filename);
        json cache;
        inp >> cache;

        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            initializers[type_id] = TypeTreeFromJSON(cache["initializers"][i]);
            finalizers[type_id] = TypeTreeFromJSON(cache["finalizers"][i]);
        }
    }

    /** Initialize scope lookup tables. */
    void CacheScopes(bool filter_usable = false) {
        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            type_remap[type_id] = (unsigned int)i;

            consumers[type_id] = std::vector<std::tuple<ScopeDef, unsigned int>>();
            producers[type_id] = std::vector<std::tuple<ScopeDef, unsigned int>>();
            users[type_id] = std::vector<std::tuple<ScopeDef, unsigned int, unsigned int>>();
        }

        for (size_t i = 0; i < _schema["scopes"].size(); ++i) {
            auto scope = _schema["scopes"][i];

            users_by_scope[i] = std::vector<std::tuple<unsigned int, unsigned int, unsigned int>>();

            ScopeDef def = MakeScopeDef(scope, (unsigned int)i);       
            scopes.push_back(def);

            if (def.in_ref.size() == 0 && def.out_ref.size() == 1) {
                is_constructor.push_back(true);
                is_destructor.push_back(false);
            } else if (def.out_ref.size() == 0 && def.in_ref.size() == 1) {
                is_constructor.push_back(false);
                is_destructor.push_back(true);
            } else {
                is_constructor.push_back(false);
                is_destructor.push_back(false);
            }

            // Mark producers and consumers.
            for (unsigned int conn_idx = 0; conn_idx < def.in_ref.size(); ++conn_idx) {
                consumers[def.in_ref[conn_idx]].push_back(std::make_tuple(def, conn_idx));
            }

            for (unsigned int conn_idx = 0; conn_idx < def.out_ref.size(); ++conn_idx) {
                producers[def.out_ref[conn_idx]].push_back(std::make_tuple(def, conn_idx));
            }

            for (unsigned int in_idx = 0; in_idx < def.in_ref.size(); ++in_idx) {
                for (unsigned int out_idx = 0; out_idx < def.out_ref.size(); ++out_idx) {
                    if (def.in_ref[in_idx] == def.out_ref[out_idx]) {
                        users[def.in_ref[in_idx]].push_back(std::make_tuple(def, in_idx, out_idx));
                        users_by_scope[i].push_back(std::make_tuple(def.in_ref[in_idx], in_idx, out_idx));
                    }
                }
            }

            // Cache signatures.
            Signature sig;
            sig.in_ref = def.in_ref;
            sig.out_ref = def.out_ref;

            if (sig_map.count(sig) == 0) {
                sig_map[sig] = std::vector<unsigned int>();
            }

            sig_map[sig].push_back(i);

            bool new_sig = true;
            for (int j = 0; j < all_sigs.size(); ++j) {
                if (all_sigs[j] == sig) {
                    new_sig = false;
                    break;
                }
            }

            all_sigs.push_back(sig);
        }
    }

    /**
     * Recursively generate a type tree for an initializer or finalizer.
     */ 
    TypeTree BuildTypeTree(unsigned int type, bool initializer, std::set<unsigned int> *avoid, bool debug=false, unsigned int max_depth=5) {
        TypeTree tree;
        tree.num_subtrees = 0;
        tree.index = type;

        std::vector<unsigned int> avoid_vec;
        for (auto it = avoid->cbegin(); it != avoid->cend(); ++it) {
            avoid_vec.push_back(*it);
        }

        auto key = std::make_tuple(type, initializer, avoid_vec);
        auto search = type_tree_cache.find(key);
        if (search != type_tree_cache.end()) {
            return search->second;
        }
        
        if (avoid->count(type) != 0 || avoid->size() > max_depth) {
            return tree;
        }

        avoid->insert(type);

        for (unsigned int sig_idx = 0; sig_idx < all_sigs.size(); ++sig_idx) {
            Signature sig = all_sigs[sig_idx];
            unsigned int sig_count = sig_map[sig].size();

            std::vector<unsigned int> *scope_up = initializer ? &sig.out_ref : &sig.in_ref;
            std::vector<unsigned int> *scope_down = initializer ? &sig.in_ref : &sig.out_ref;

            // Search for matching types.
            for (unsigned int conn_idx = 0; conn_idx < scope_up->size(); ++conn_idx) {
                if (scope_up->operator[](conn_idx) != type) continue;

                // Create new scope node.
                ScopeTree stree;
                stree.num_subtrees = sig_count;
                stree.sig_idx = sig_idx;
                stree.conn_idx = conn_idx;

                // Iterate forward children.
                for (unsigned int child = 0; child < scope_down->size(); ++child) {
                    TypeTree child_tree = BuildTypeTree(scope_down->operator[](child), initializer, avoid, debug, max_depth);
                    
                    stree.num_subtrees *= child_tree.num_subtrees;
                    stree.children.push_back(child_tree);
                }

                // Iterate reverse children.
                for (unsigned int child = 0; child < scope_up->size(); ++child) {
                    if (child == conn_idx) {
                        continue;
                    }

                    TypeTree child_tree = BuildTypeTree(scope_up->operator[](child), !initializer, avoid, debug, max_depth);

                    stree.num_subtrees *= child_tree.num_subtrees;
                    stree.rev_children.push_back(child_tree);
                }

                // If this is a valid (non-zero) scope tree, add it to the parent.
                if (stree.num_subtrees > 0) {
                    tree.num_subtrees += stree.num_subtrees;
                    tree.children.push_back(stree);
                }
            }
        }

        avoid->erase(type);

        // Add to cache.
        type_tree_cache[key] = tree;

        return tree;
    }

    TypeTree BuildTypeTree(unsigned int type, bool initializer, bool debug=false, unsigned int max_depth=5) {
        std::set<unsigned int> avoid;
        return BuildTypeTree(type, initializer, &avoid, debug, max_depth);
    }

    ScopeDef SampleSignatureIndex(unsigned int sig_idx) {
        Signature sig = all_sigs[sig_idx];

        std::vector<unsigned int> possible_scopes = sig_map[sig];
        unsigned int scope_idx = possible_scopes[rand() % possible_scopes.size()];

        return GetScope(scope_idx);
    }

    /**
     * Returns a random scopedef with the same signature as the input.
     */
    ScopeDef WithMatchingSignature(ScopeDef def) {
        Signature sig;
        sig.in_ref = def.in_ref;
        sig.out_ref = def.out_ref;

        std::vector<unsigned int> possible_scopes = sig_map[sig];
        unsigned int scope_idx = possible_scopes[rand() % possible_scopes.size()];

        return GetScope(scope_idx);
    }

    void CacheTypeTrees(bool debug=false, unsigned int max_depth=5) {
        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            initializers[type_id] = BuildTypeTree(type_id, true, debug, max_depth);
            finalizers[type_id] = BuildTypeTree(type_id, false, debug, max_depth);

            if (debug) {
                std::cerr << "Tree for: " << _schema["types"][i]["name"] << std::endl;
                PrintTypeTree(initializers[type_id]);
                PrintTypeTree(finalizers[type_id]);
            }
        }
    }

    bool IsScopeValid(ScopeDef scope, std::unordered_set<unsigned int> invalid_types) {
        bool usable = true;

        for (unsigned int j : scope.in_ref) {
            if (invalid_types.count(j) != 0) {
                usable = false;
            }
        }

        for (unsigned int j : scope.out_ref) {
            if (invalid_types.count(j) != 0) {
                usable = false;
            }
        }
        
        return usable;
    }

    void CacheUsable(std::unordered_set<unsigned int> invalid_types) {
        // Iterate over scopes and invalidate ones that can't be used.
        for (size_t i = 0; i < scopes.size(); ++i) {
            if (IsScopeValid(scopes[i], invalid_types)) {
                usable_scopes.push_back((unsigned int)i);
            }
        }

        // Iterate over producers & consumers.
        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            usable_producers[type_id] = std::vector<unsigned int>();
            usable_consumers[type_id] = std::vector<unsigned int>();
            usable_users[type_id] = std::vector<unsigned int>();

            for (size_t j = 0; j < producers[type_id].size(); ++j) {
                ScopeDef scope = std::get<0>(producers[type_id][j]);
                if (IsScopeValid(scope, invalid_types)) {
                    usable_producers[type_id].push_back((unsigned int)j);
                }
            }

            for (size_t j = 0; j < consumers[type_id].size(); ++j) {
                ScopeDef scope = std::get<0>(consumers[type_id][j]);
                if (IsScopeValid(scope, invalid_types)) {
                    usable_consumers[type_id].push_back((unsigned int)j);
                }
            }

            for (size_t j = 0; j < users[type_id].size(); ++j) {
                ScopeDef scope = std::get<0>(users[type_id][j]);
                if (IsScopeValid(scope, invalid_types)) {
                    usable_users[type_id].push_back((unsigned int)j);
                }
            }
        }
    }

    /** Validate the schema by ensuring all types can be created and destroyed. */
    bool Validate(bool debug=false, unsigned int max_depth=5, bool skip_validation=false, bool prune_cache=false) {
        CacheScopes();

        if (skip_validation) {
            return true;
        }

        std::ifstream cache_file("cache.json");
        if (cache_file.good() && !prune_cache) {
            // Load type trees from cache.
            std::cerr << "[*] GraphFuzz: loading trees from cache..." << std::endl;
            LoadCached("cache.json");
        } else {
            std::cerr << "[*] GraphFuzz: resetting cache..." << std::endl;
            CacheTypeTrees(debug, max_depth);
            SaveCached("cache.json");
        }

        std::unordered_set<unsigned int> invalid_types;

        for (size_t i = 0; i < _schema["types"].size(); ++i) {
            unsigned int type_id = (unsigned int)_schema["types"][i]["id"];

            bool is_valid = true;

            if (initializers[type_id].num_subtrees == 0) {
                std::cerr << "[!] No initializer tree for type: " << _schema["types"][i]["name"] \
                    << " (type: " << type_id << ")" << std::endl;
                is_valid = false;
            }

            if (finalizers[type_id].num_subtrees == 0) {
                std::cerr << "[!] No finalizer tree for type: " << _schema["types"][i]["name"] \
                    << " (type: " << type_id << ")" << std::endl;
                is_valid = false;
            }

            if (!is_valid) {
                invalid_types.insert(type_id);
            }
        }

        CacheUsable(invalid_types);

        std::cerr << "[*] After validation: total scopes: " << scopes.size() << std::endl;
        std::cerr << "[*] After validation: usable scopes: " << usable_scopes.size() << std::endl;

        return invalid_types.size() == 0;
    }

    /** Returns a random scope. */
    ScopeDef GetRandomScope() {
        unsigned int scope_idx = usable_scopes[rand() % usable_scopes.size()];
        return scopes[scope_idx];
    }

    std::vector<unsigned int> GetUsableScopes() {
        return usable_scopes;
    }

    ScopeDef GetScope(unsigned int idx) {
        return scopes[idx];
    }

    std::tuple<ScopeDef, unsigned int> GetRandomProducer(unsigned int type) {
        auto usable = usable_producers[type];
        unsigned int idx = usable[rand() % usable.size()];
        return producers[type][idx];
    }

    std::tuple<ScopeDef, unsigned int> GetRandomConsumer(unsigned int type) {
        auto usable = usable_consumers[type];
        unsigned int idx = usable[rand() % usable.size()];
        return consumers[type][idx];
    }

    /**
     * Returns a scope with signature: (? x T x ?)->(? x T x ?)
     */
    std::tuple<ScopeDef, unsigned int, unsigned int> GetRandomUser(unsigned int type) {
        auto usable = usable_users[type];
        unsigned int idx = usable[rand() % usable.size()];
        return users[type][idx];
    }

    bool HasUser(unsigned int type) {
        return usable_users[type].size() > 0;
    }

    bool IsSpliceable(unsigned int scope_idx) {
        return users_by_scope[scope_idx].size() > 0;
    }

    std::tuple<unsigned int, unsigned int, unsigned int> GetRandomSplicePath(unsigned int scope_idx) {
        auto vec = users_by_scope[scope_idx];
        return vec[rand() % vec.size()];
    }

    bool IsDestructor(unsigned int type) {
        return is_destructor[type];
    }

    bool IsConstructor(unsigned int type) {
        return is_constructor[type];
    }

    void PrintScopeTree(ScopeTree tree, int n=0) {
        for (int i = 0; i < n; ++i) std::cerr << " ";
        if (tree.children.size() == 0 && tree.rev_children.size() == 0) {
            std::cerr << "(sig:" << tree.sig_idx << " (" << tree.num_subtrees << "))" << std::endl;
        } else {
            std::cerr << "(sig:" << tree.sig_idx << " (" << tree.num_subtrees << ")" << std::endl;
            for (size_t j = 0; j < tree.children.size(); ++j) {
                PrintTypeTree(tree.children[j], n+2);
            }
            for (int i = 0; i < n; ++i) std::cerr << " ";
            std::cerr << "<>" << std::endl;
            for (size_t j = 0; j < tree.rev_children.size(); ++j) {
                PrintTypeTree(tree.rev_children[j], n+2);
            }
            for (int i = 0; i < n; ++i) std::cerr << " ";
            std::cerr << ")" << std::endl;
        }
    }

    void PrintTypeTree(TypeTree tree, int n=0) {
        for (int i = 0; i < n; ++i) std::cerr << " ";
        unsigned int type_idx = type_remap[tree.index];
        if (tree.children.size() == 0) {
            std::cerr << "(" << _schema["types"][type_idx]["name"] << " (" << tree.num_subtrees << "))" << std::endl;
        } else {
            std::cerr << "(" << _schema["types"][type_idx]["name"] << " (" << tree.num_subtrees << ")" << std::endl;
            for (size_t j = 0; j < tree.children.size(); ++j) {
                PrintScopeTree(tree.children[j], n+2);
            }
            for (int i = 0; i < n; ++i) std::cerr << " ";
            std::cerr << ")" << std::endl;
        }
    }

    TypeTree GetInitializer(unsigned int type) {
        return initializers[type];
    }

    TypeTree GetFinalizer(unsigned int type) {
        return finalizers[type];
    }
};
