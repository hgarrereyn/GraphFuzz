
#include "graph.hpp"

#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#ifdef TRACE_MUTATIONS
#include <openssl/sha.h>
#endif

using namespace std;


#define DBG_PRINT 0

// Maximum number of input/output arguments for stack array sizing.
#define MAX_CONN 20

// Fuzzer entrypoint.
extern "C" void (*FUZZER_SHIMS[])(void **, void **, const char *);
extern "C" void global_init(int *argc, char ***argv);
extern "C" void shim_init();
extern "C" void shim_finalize();

// Fuzzer mutation API.
extern "C" size_t LLVMFuzzerCustomMutator(uint8_t *Data, size_t Size, size_t MaxSize, unsigned int Seed);
extern "C" int MutateOne(const char *s_seed, const char *in_file, const char *out_file);
extern "C" int InitCorpus(const char *init_corpus_dir);

// Saved jump buffer.
static jmp_buf buf;

static bool mark_invalid;
static bool will_bail;

// Global schema.
Schema *global_schema;

// Command line flags:
std::vector<int> graphfuzz_catch = std::vector<int>();
bool graphfuzz_debug = false;
unsigned int graphfuzz_scope_max_depth = 10;
bool graphfuzz_skip_validation = false;
float graphfuzz_context_mutation_prob = 0.95; // Probability of performing mutation on context variables.
bool graphfuzz_enable_soft_execution = false;
bool graphfuzz_ignore_invalid = false;
int graphfuzz_max_nodes = 200; // Max nodes per graph.
const char *graphfuzz_schema_path = "schema.json";

// mutation trace api
bool graphfuzz_trace_mutations = false;
bool has_log = false;
ofstream mutation_log;

#define MUT_LOG_CONTEXT (-1);
#define MUT_LOG_CREATE (-2);
#define MUT_LOG_CROSSOVER (-3);

// If true, refresh the cache.json file.
bool graphfuzz_prune_cache = false;


void sig_handler(int a) {
    // Return to the pre-configured jump target.
    siglongjmp(buf, 1);
}

void register_signals() {
    struct sigaction action;
    action.sa_handler = sig_handler;
    for (auto num : graphfuzz_catch) {
        sigaction(num, &action, NULL);
    }
}

std::vector<int> readInts(char *input) {
    std::vector<int> ints;

    char *inp = strdup(input);

    char *tok = strtok(inp, ",");
    while (tok != NULL) {
        ints.push_back(atoi(tok));
        tok = strtok(NULL, ",");
    }

    free(inp);

    return ints;
}

const char HEX_DIGIT[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

std::string hexlify(unsigned char *arr, int size) {
    std::stringstream str;
    for (int i = 0; i < size; ++i) {
        str << HEX_DIGIT[arr[i] >> 4];
        str << HEX_DIGIT[arr[i] & 0xf];
    }
    return str.str();
}

extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv) {
    bool mutate_one = false;
    const char *mutate_seed;
    const char *mutate_in;
    const char *mutate_out;

    int *orig_argc = argc;
    char ***orig_argv = argv;

    bool init_corpus = false;
    const char *init_corpus_dir;

    for (int i = 0; i < *argc; ++i) {
        char *opt = (*argv)[i];
        if (strcmp(opt, "--graphfuzz_debug") == 0) graphfuzz_debug = true;
        if (strcmp(opt, "--graphfuzz_skip_validation") == 0) graphfuzz_skip_validation = true;
        if (strcmp(opt, "--graphfuzz_prune_cache") == 0) graphfuzz_prune_cache = true;
        if (strcmp(opt, "--graphfuzz_enable_soft_execution") == 0) graphfuzz_enable_soft_execution = true;
        if (strcmp(opt, "--graphfuzz_ignore_invalid") == 0) graphfuzz_ignore_invalid = true;
        #ifdef TRACE_MUTATIONS
        if (strcmp(opt, "--graphfuzz_trace_mutations") == 0) graphfuzz_trace_mutations = true;
        #endif

        if (strncmp(opt, "--graphfuzz_catch=", 18) == 0) {
            graphfuzz_catch = readInts(opt + 18);
            cout << "[*] GraphFuzz: will catch execeptions:" << endl;
            for (auto num : graphfuzz_catch) {
                cout << "  - " << num << endl;
            }
        }

        if (strncmp(opt, "--graphfuzz_scope_max_depth=", 28) == 0) {
            const char *val = opt + 28;
            graphfuzz_scope_max_depth = atoi(val);
            cout << "[*] GraphFuzz: scope_max_depth = " << graphfuzz_scope_max_depth << endl;
        }

        if (strncmp(opt, "--graphfuzz_context_mutation_prob=", 34) == 0) {
            const char *val = opt + 34;
            graphfuzz_context_mutation_prob = atof(val);
            cout << "[*] GraphFuzz: context_mutation_prob = " << graphfuzz_context_mutation_prob << endl;
        }

        if (strncmp(opt, "--graphfuzz_max_nodes=", 22) == 0) {
            const char *val = opt + 22;
            graphfuzz_max_nodes = atoi(val);
            cout << "[*] GraphFuzz: max_nodes = " << graphfuzz_max_nodes << endl;
        }

        if (strncmp(opt, "--graphfuzz_schema=", 19) == 0) {
            const char *val = opt + 19;
            graphfuzz_schema_path = val;
            cout << "[*] GraphFuzz: schema path = " << graphfuzz_schema_path << endl;
        }

        // External mutation API.
        // --graphfuzz_mutate_one <seed> <input> <output>
        if (strcmp(opt, "--graphfuzz_mutate_one") == 0) {
            assert(i + 3 < *argc);
            mutate_one = true;
            mutate_seed = (*argv)[i+1];
            mutate_in = (*argv)[i+2];
            mutate_out = (*argv)[i+3];
            i += 3;
        }

        // External completion API.
        // --graphfuzz_init_corpus <corpus>
        if (strcmp(opt, "--graphfuzz_init_corpus") == 0) {
            assert(i + 1 < *argc);
            init_corpus = true;
            init_corpus_dir = (*argv)[i+1];
        }

        if (graphfuzz_trace_mutations) {
            cout << "[*] GraphFuzz: tracing mutations..." << endl;
        }
    }

    global_schema = Schema::FromFile(graphfuzz_schema_path);
    if (!global_schema->Validate(
            graphfuzz_debug, 
            graphfuzz_scope_max_depth, 
            graphfuzz_skip_validation,
            graphfuzz_prune_cache)) {
        if (graphfuzz_ignore_invalid) {
            cout << "[!] Schema is invalid. Running anyways..." << endl;
        } else {
            cerr << "[!] Schema is invalid. (Run with \"--graphfuzz_ignore_invalid\" to continue with usable scopes)." << endl;
            exit(-1);
        }
    }

    register_signals();

    if (mutate_one) {
        int res = MutateOne(mutate_seed, mutate_in, mutate_out);
        exit(res);
    } else if (init_corpus) {
        int res = InitCorpus(init_corpus_dir);
        exit(res);
    }

    global_init(orig_argc, orig_argv);

    return 0;
}

extern "C" int MutateOne(const char *s_seed, const char *in_file, const char *out_file) {
    cout << "[*] GraphFuzz: mutate one <" << in_file << ">::<" << out_file << ">" << endl;

    unsigned int seed = (unsigned int)atoi(s_seed);

    fstream ex_file;
    stringstream ex_dat;
    ex_file.open(in_file);
    ex_dat << ex_file.rdbuf();
    ex_file.close();
    string ex_str = ex_dat.str();

    uint8_t ex_buffer[ex_str.size()];
    memcpy(ex_buffer, ex_str.c_str(), ex_str.size());

    size_t out_size = LLVMFuzzerCustomMutator(ex_buffer, ex_str.size(), ex_str.size(), seed);

    if (graphfuzz_debug) {
        cout << "Input size: " << ex_str.size() << endl;
        cout << "Output size: " << out_size << endl;
    }

    if (out_size == 0 || out_size > ex_str.size()) {
        return -1;
    }

    ofstream out(out_file);
    out.write((const char *)ex_buffer, out_size);

    return 0;
}

extern "C" int InitCorpus(const char *init_corpus_dir) {
    cout << "[*] Init corpus" << endl;
    std::string base_dir(init_corpus_dir);
    
    std::vector<unsigned int> usable = global_schema->GetUsableScopes();

    for (int i = 0; i < usable.size(); ++i) {
        ScopeDef def = global_schema->GetScope(usable[i]);
        cout << "\t[" << usable[i] << "] :: " << def.name << endl;

        TGraph g = TGraph(global_schema);
        g.CreateWithScope(def);

        std::string fpath = base_dir + "/seed_" + to_string(i);
        
        bool err = false;
        string out_str = g.Write(&err);
        if (err) return -1;

        ofstream out(fpath);
        out.write(out_str.data(), out_str.size());
    }

    cout << "[*] Done" << endl;

    return 0;
}

extern "C" size_t LLVMFuzzerCustomMutator(uint8_t *Data, size_t Size, size_t MaxSize, unsigned int Seed) {
    string inp = string((const char *)Data, Size);

    int mut_id = MUT_LOG_CREATE;

    TGraph g = TGraph(global_schema);
    if (!g.Read(inp) || !g.Validate()) {
        // Create a new graph.
        if (!g.Create(Seed, graphfuzz_max_nodes)) return 0;
    } else {
        // Mutate existing graph.
        if (!g.Mutate(Seed, graphfuzz_max_nodes, graphfuzz_context_mutation_prob, &mut_id)) {
            if (graphfuzz_debug) cout << "mutate failed" << endl;
            return 0;
        }
    }

    bool err = false;
    string out = g.Write(&err);
    if (err || out.size() > MaxSize) return 0;

    #ifdef TRACE_MUTATIONS
    if (graphfuzz_trace_mutations) {
        if (!has_log) {
            pid_t pid = getpid();
            string log_path = ".mutation_log." + to_string(pid);
            mutation_log = ofstream(log_path, ofstream::out | ofstream::app);
            has_log = true;
        }

        unsigned char hash1[SHA_DIGEST_LENGTH];
        unsigned char hash2[SHA_DIGEST_LENGTH];

        SHA1((unsigned char *)inp.data(), inp.size(), hash1);
        SHA1((unsigned char *)out.data(), out.size(), hash2);

        time_t curr_time = time(NULL);

        stringstream str;
        str << hexlify((unsigned char *)hash1, SHA_DIGEST_LENGTH) << "," \
            << hexlify((unsigned char *)hash2, SHA_DIGEST_LENGTH) << "," \
            << mut_id << "," \
            << curr_time << endl;
        string out_string = str.str();

        {
            mutation_log.write(out_string.data(), out_string.size());
            mutation_log.flush();
        }
    }
    #endif

    memcpy(Data, out.data(), out.size());
    return out.size();
}

extern "C" size_t LLVMFuzzerCustomCrossOver(const uint8_t *Data1, size_t Size1, const uint8_t *Data2, size_t Size2, uint8_t *Out, size_t MaxOutSize, unsigned int Seed) {
    string inp1 = string((const char *)Data1, Size1);
    string inp2 = string((const char *)Data2, Size2);

    TGraph g1 = TGraph(global_schema);
    TGraph g2 = TGraph(global_schema);

    if (!g1.Read(inp1) || !g1.Validate() || !g2.Read(inp2) || !g2.Validate()) {
        // Create a new graph.
        if (!g1.Create(Seed, graphfuzz_max_nodes)) return 0;
    } else {
        // Crossover.

        if (graphfuzz_debug) {
            cout << "G1:" << endl;
            g1.PrintAll();
            cout << "G2:" << endl;
            g2.PrintAll();
        }

        if (!g1.Cross(g2, Seed, graphfuzz_max_nodes)) {
            if (graphfuzz_debug) cout << "crossover failed" << endl;
            return 0;
        }

        if (graphfuzz_debug) {
            cout << "Cross:" << endl;
            g1.PrintAll();
        }
    }

    bool err = false;
    string out = g1.Write(&err);
    if (err || out.size() > MaxOutSize) return 0;

    #ifdef TRACE_MUTATIONS
    if (graphfuzz_trace_mutations) {
        if (!has_log) {
            pid_t pid = getpid();
            string log_path = ".mutation_log." + to_string(pid);
            mutation_log = ofstream(log_path, ofstream::out | ofstream::app);
            has_log = true;
        }

        unsigned char hash1[SHA_DIGEST_LENGTH];
        unsigned char hash2[SHA_DIGEST_LENGTH];
        unsigned char hash3[SHA_DIGEST_LENGTH];

        SHA1((unsigned char *)inp1.data(), inp1.size(), hash1);
        SHA1((unsigned char *)inp2.data(), inp2.size(), hash2);
        SHA1((unsigned char *)out.data(), out.size(), hash3);

        time_t curr_time = time(NULL);

        int mut_id = MUT_LOG_CROSSOVER;

        stringstream str;
        str << hexlify((unsigned char *)hash1, SHA_DIGEST_LENGTH) << "," \
            << hexlify((unsigned char *)hash2, SHA_DIGEST_LENGTH) << "," \
            << hexlify((unsigned char *)hash3, SHA_DIGEST_LENGTH) << "," \
            << mut_id << "," \
            << curr_time << endl;
        string out_string = str.str();

        {
            mutation_log.write(out_string.data(), out_string.size());
            mutation_log.flush();
        }
    }
    #endif

    memcpy(Out, out.data(), out.size());
    return out.size();
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    int val = sigsetjmp(buf, 1);
    if (val != 0) {
        return 0;
    }

    // Call shim_init() immediately to ensure we always have coverage data.
    shim_init();

    if (Size == 0) return 0; // Ignore empty inputs.
    string inp = string((const char *)Data, Size);

    TGraph g = TGraph(global_schema);
    if (!g.Read(inp)) {
        if (graphfuzz_debug) cout << "invalid proto" << endl;
        return 0;
    }
    if (!g.Validate()) {
        if (graphfuzz_debug) cout << "invalid" << endl;
        return 0;
    }

    if (graphfuzz_debug) g.PrintAll();

    vector<Node> nodes = g.GetOrderedNodes();
    void *ref[nodes.size()][MAX_CONN];

    for (Node n : nodes) {
        void *in_ref[n.in_ref_size()];
        void *out_ref[n.out_ref_size()];
        const char *context = n.context().data();

        // Load inputs.
        for (int i = 0; i < n.in_ref_size(); ++i) {
            in_ref[i] = ref[n.index()][i];
            if (graphfuzz_debug) {
                cout << "Prepare input: " << i << " :: " << in_ref[i] << endl;
            }
        }

        // Mark input as valid.
        mark_invalid = false;

        // Unset bail flag.
        will_bail = false;

        // Invoke shim.
        void (*func)(void **, void **, const char *) = FUZZER_SHIMS[n.type()];
        func(in_ref, out_ref, context);

        if (will_bail) {
            // Target called graphfuzz_bail()
            if (graphfuzz_debug) {
                cout << "Bailing..." << endl;
            }
            return mark_invalid;
        }

        // Copy outputs.
        for (int i = 0; i < n.out_ref_size(); ++i) {
            NodeRef r = n.out_ref(i);
            ref[r.node_idx()][r.conn_idx()] = out_ref[i];
            if (graphfuzz_debug) {
                cout << "Got output: " << i << " :: " << out_ref[i] << endl;
            }
        }
    }

    shim_finalize();

    return mark_invalid;
}

extern "C" void graphfuzz_invalid() {
    mark_invalid = true;
}

extern "C" int graphfuzz_try() {
    if (graphfuzz_enable_soft_execution) {
        return sigsetjmp(buf, 1);
    } else {
        return 0;
    }
}

extern "C" void graphfuzz_bail() {
    will_bail = true;
}
