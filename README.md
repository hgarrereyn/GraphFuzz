# GraphFuzz: _Library API Fuzzing with Lifetime-aware Dataflow Graphs_

GraphFuzz is an experimental framework for building structure-aware, library API fuzzers.

Read our ICSE'22 paper: [GraphFuzz: Library API Fuzzing with Lifetime-aware Dataflow Graphs](https://hgarrereyn.github.io/GraphFuzz/research/GraphFuzz_ICSE_2022.pdf)

GraphFuzz consists of:
- `gfuzz`: A command-line tool to synthesize harnesses
- `libgraphfuzz`: A runtime graph-mutation engine

Documentation: [hgarrereyn.github.io/GraphFuzz](https://hgarrereyn.github.io/GraphFuzz)

## How it Works

With GraphFuzz, you create a _schema_ that describes your target library API. The schema is written in human-readable YAML and contains a list of all functions, classes and structs that you want to fuzz test:

**schema.yaml**
```yaml
Foo:
    methods:
    - Foo()
    - ~Foo()
    - void foo(int x, int y, float z)
Bar:
    methods:
    - Bar(Foo *, int)
    - ~Bar()
    - void bar(int x)
```

At runtime, GraphFuzz will generate test cases that invoke your library API in different orders and with different arguments. Importantly, it will explicily track object lifetimes and ensure that all test cases respect the API contract defined by the schema:

```cpp
{ // Example 1
    Foo *v0 = new Foo();
    v0->foo(3, 4, 0.5);
    Bar *v1 = new Bar(v0, 1000);
    v1->bar(123);
    del v1;
    del v0;
}
{ // Example 2
    Foo *v0 = new Foo();
    v0->foo(3, 4, 0.5);
    v0->foo(1, 0, 0.5);
    v0->foo(0, 4, 0.5);
    del v0;
}
{ // Example 3
    Foo *v0 = new Foo();
    v0->foo(3, 4, 0.5);
    Bar *v1 = new Bar(v0, 1000);
    Bar *v2 = new Bar(v0, 0);
    del v2;
    del v1;
    del v0;
}
```

The example test cases above are represented as C++ source code. However, internally, GraphFuzz represents every test case as a _dataflow graph_ where vertices are functions and edges are object dependencies (hence **Graph**Fuzz). In this way, GraphFuzz executes test cases _without_ code synthesis or recompilation; rather, it dynamically traverses each graph, invoking one endpoint per vertex.

![a](docs/assets/readme_graphs.png)

## Using GraphFuzz

GraphFuzz is implemented as a custom mutation engine on top of libFuzzer and as such it can be easily incorporated into build systems that already handle libFuzzer harnesses.

1. Use `gfuzz` to synthesize C++ harness files from your `schema.yaml` harness spec.

```
gfuzz gen cpp schema.yaml .
```

2. Compile the generated harness files as standard libFuzzer harnesses (`-fsanitize=fuzzer`) and link libgraphfuzz and protobuf dependencies (`-lgraphfuzz -lprotobuf`). Optionally, include any extra sanitizers (ASAN, UBSAN, TSAN, etc...). GraphFuzz will actually create two mirror harnesses: `fuzz_exec` is used for fuzzing and actually invokes the library API while `fuzz_write` generates equivalent source code for a given dataflow graph.

```bash
# fuzz_exec: main fuzzer, executes test cases
clang++ fuzz_exec.cpp \
    -lgraphfuzz -lprotobuf \
    -fsanitize=address,fuzzer \
    -o fuzz_exec

# fuzz_write: converts test cases to source code
clang++ fuzz_write.cpp \
    -lgraphfuzz -lprotobuf \
    -fsanitize=address,fuzzer \
    -o fuzz_write
```

3. Run the generated binary with any standard libFuzzer command-line arguments. In addition, there are several additional GraphFuzz-specific arguments prefixed with `--graphfuzz-`. Crash reports are identical to standard libFuzzer reports.

```
$ ./fuzz_exec

[*] Loading: schema.json
[*] GraphFuzz: loading trees from cache...
[*] After validation: total scopes: 4
[*] After validation: usable scopes: 4
INFO: Seed: 545606100
INFO: Loaded 1 modules   (13 inline 8-bit counters): 13 [0x82f2c0, 0x82f2cd),
INFO: Loaded 1 PC tables (13 PCs): 13 [0x5de960,0x5dea30),
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: A corpus is not provided, starting from an empty corpus
#2	INITED cov: 1 ft: 1 corp: 1/1b exec/s: 0 rss: 39Mb
	NEW_FUNC[0/6]: 0x554910 in shim_finalize (/harness/in/fuzz/fuzz_exec+0x554910)
	NEW_FUNC[1/6]: 0x554b70 in shim_1 (/harness/in/fuzz/fuzz_exec+0x554b70)
#3	NEW    cov: 7 ft: 8 corp: 2/206b exec/s: 0 rss: 43Mb L: 205/205 MS: 1 Custom-
#4	NEW    cov: 7 ft: 9 corp: 3/224b exec/s: 0 rss: 43Mb L: 18/205 MS: 1 CustomCrossOver-
#32	NEW    cov: 7 ft: 12 corp: 4/600b exec/s: 0 rss: 44Mb L: 376/376 MS: 4 CustomCrossOver-ChangeBinInt-Custom-CustomCrossOver-
#35	NEW    cov: 7 ft: 15 corp: 5/1336b exec/s: 0 rss: 44Mb L: 736/736 MS: 5 ShuffleBytes-Custom-CrossOver-Custom-CustomCrossOver-
#55	NEW    cov: 7 ft: 18 corp: 6/1894b exec/s: 0 rss: 45Mb L: 558/736 MS: 6 CustomCrossOver-Custom-ChangeByte-Custom-CustomCrossOver-CustomCrossOver-
#78	NEW    cov: 7 ft: 19 corp: 7/2812b exec/s: 0 rss: 46Mb L: 918/918 MS: 4 CustomCrossOver-ChangeBit-Custom-CustomCrossOver-
#84	REDUCE cov: 7 ft: 19 corp: 7/2803b exec/s: 0 rss: 46Mb L: 196/918 MS: 1 CustomCrossOver-
	NEW_FUNC[0/2]: 0x554930 in shim_0 (/harness/in/fuzz/fuzz_exec+0x554930)
	NEW_FUNC[1/2]: 0x555160 in Test::fuzz1(int*) (/harness/in/fuzz/fuzz_exec+0x555160)
#85	NEW    cov: 10 ft: 22 corp: 8/2860b exec/s: 0 rss: 46Mb L: 57/918 MS: 1 CustomCrossOver-
#86	REDUCE cov: 10 ft: 22 corp: 8/2712b exec/s: 0 rss: 47Mb L: 770/770 MS: 1 Custom-
#102	NEW    cov: 10 ft: 23 corp: 9/3660b exec/s: 0 rss: 47Mb L: 948/948 MS: 1 CustomCrossOver-
#115	REDUCE cov: 10 ft: 27 corp: 10/4822b exec/s: 0 rss: 48Mb L: 1162/1162 MS: 3 CustomCrossOver-CustomCrossOver-CustomCrossOver-
#280	NEW    cov: 10 ft: 30 corp: 11/6672b exec/s: 0 rss: 55Mb L: 1850/1850 MS: 7 CustomCrossOver-ChangeBinInt-Custom-CrossOver-Custom-CustomCrossOver-CustomCrossOver-
#286	REDUCE cov: 10 ft: 30 corp: 11/6665b exec/s: 0 rss: 56Mb L: 50/1850 MS: 1 CustomCrossOver-
#307	NEW    cov: 10 ft: 31 corp: 12/8335b exec/s: 0 rss: 57Mb L: 1670/1850 MS: 1 CustomCrossOver-
#310	NEW    cov: 10 ft: 32 corp: 13/10937b exec/s: 0 rss: 57Mb L: 2602/2602 MS: 4 CustomCrossOver-CMP-Custom-CustomCrossOver- DE: "num_s"-
#318	REDUCE cov: 10 ft: 32 corp: 13/10757b exec/s: 0 rss: 58Mb L: 1490/2602 MS: 5 ShuffleBytes-Custom-PersAutoDict-Custom-CustomCrossOver- DE: "num_s"-
#319	NEW    cov: 10 ft: 33 corp: 14/12967b exec/s: 0 rss: 58Mb L: 2210/2602 MS: 1 CustomCrossOver-
#338	NEW    cov: 10 ft: 36 corp: 15/16289b exec/s: 0 rss: 60Mb L: 3322/3322 MS: 7 EraseBytes-Custom-CMP-Custom-EraseBytes-Custom-CustomCrossOver- DE: "finalizers"-
#339	NEW    cov: 10 ft: 37 corp: 16/18Kb exec/s: 0 rss: 60Mb L: 2242/3322 MS: 1 CustomCrossOver-
#384	NEW    cov: 10 ft: 38 corp: 17/21Kb exec/s: 0 rss: 63Mb L: 3110/3322 MS: 5 CustomCrossOver-Custom-Custom-Custom-CustomCrossOver-
#390	NEW    cov: 10 ft: 41 corp: 18/24Kb exec/s: 0 rss: 63Mb L: 3174/3322 MS: 1 CustomCrossOver-
#392	REDUCE cov: 10 ft: 42 corp: 19/27Kb exec/s: 0 rss: 63Mb L: 3142/3322 MS: 2 CustomCrossOver-CustomCrossOver-
#483	NEW    cov: 10 ft: 43 corp: 20/30Kb exec/s: 0 rss: 74Mb L: 3714/3714 MS: 1 CustomCrossOver-
#515	NEW    cov: 10 ft: 46 corp: 21/34Kb exec/s: 0 rss: 80Mb L: 3386/3714 MS: 3 EraseBytes-Custom-CustomCrossOver-
#537	REDUCE cov: 10 ft: 46 corp: 21/34Kb exec/s: 0 rss: 83Mb L: 1342/3714 MS: 2 CustomCrossOver-CustomCrossOver-
...
ChangeByte-Custom-CrossOver-Custom-ChangeBit-Custom-ShuffleBytes-Custom-CustomCrossOver-
#22527	REDUCE cov: 11 ft: 72 corp: 40/47Kb exec/s: 1072 rss: 590Mb L: 1198/4024 MS: 3 EraseBytes-Custom-CustomCrossOver-
#22794	REDUCE cov: 11 ft: 72 corp: 40/47Kb exec/s: 1085 rss: 590Mb L: 112/4024 MS: 2 Custom-CustomCrossOver-
#22973	REDUCE cov: 11 ft: 72 corp: 40/47Kb exec/s: 1093 rss: 591Mb L: 1476/4024 MS: 6 CopyPart-Custom-CustomCrossOver-ShuffleBytes-Custom-CustomCrossOver-
==39== ERROR: libFuzzer: deadly signal
    #0 0x523c09 in __sanitizer_print_stack_trace (/harness/in/fuzz/fuzz_exec+0x523c09)
    #1 0x434106 in fuzzer::Fuzzer::CrashCallback() (/harness/in/fuzz/fuzz_exec+0x434106)
    #2 0x43415f in fuzzer::Fuzzer::StaticCrashSignalCallback() (/harness/in/fuzz/fuzz_exec+0x43415f)
    #3 0x7f5d0329f97f  (/lib/x86_64-linux-gnu/libpthread.so.0+0x1297f)
    #4 0x55528d in Test::fuzz1(int*) (/harness/in/fuzz/fuzz_exec+0x55528d)
    #5 0x554abe in shim_0 (/harness/in/fuzz/fuzz_exec+0x554abe)
    #6 0x5581f1 in LLVMFuzzerTestOneInput (/harness/in/fuzz/fuzz_exec+0x5581f1)
    #7 0x434847 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/harness/in/fuzz/fuzz_exec+0x434847)
    #8 0x43f0b4 in fuzzer::Fuzzer::MutateAndTestOne() (/harness/in/fuzz/fuzz_exec+0x43f0b4)
    #9 0x44071f in fuzzer::Fuzzer::Loop(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, fuzzer::fuzzer_allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&) (/harness/in/fuzz/fuzz_exec+0x44071f)
    #10 0x42fadc in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/harness/in/fuzz/fuzz_exec+0x42fadc)
    #11 0x4229a2 in main (/harness/in/fuzz/fuzz_exec+0x4229a2)
    #12 0x7f5d02899bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #13 0x422a19 in _start (/harness/in/fuzz/fuzz_exec+0x422a19)

NOTE: libFuzzer has rudimentary signal handlers.
      Combine libFuzzer with AddressSanitizer or similar for better crash reports.
SUMMARY: libFuzzer: deadly signal
MS: 8 EraseBytes-Custom-CopyPart-Custom-ChangeBinInt-Custom-ChangeBit-Custom-; base unit: 34135396532491fa3706b611a9ebd0665e5fa6d0
artifact_prefix='./'; Test unit written to ./crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53
```

4. Upon finding a crash, use `fuzz_write` to convert the serialized dataflow graph into source code which can be recompiled externally for debugging purposes:

```
$ ./fuzz_write ./crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53
...

#include "lib.h"


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)

int main() {
    Test *var_0;
    { // begin shim_2
        var_0 = MAKE(Test);
        Test ref = Test();
        *var_0 = ref;
    } // end shim_2
    Test *var_1;
    { // begin shim_1
    int _a0[32] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    float _a1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        var_0->fuzz2(_a0, _a1);
        var_1 = var_0;
    } // end shim_1
    Test *var_2;
    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_1->fuzz1(_a0);
        var_2 = var_1;
    } // end shim_0
    Test *var_3;
    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_2->fuzz1(_a0);
        var_3 = var_2;
    } // end shim_0
    Test *var_4;
    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_3->fuzz1(_a0);
        var_4 = var_3;
    } // end shim_0
    Test *var_5;
    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_4->fuzz1(_a0);
        var_5 = var_4;
    } // end shim_0
    Test *var_6;
    { // begin shim_1
    int _a0[32] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    float _a1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        var_5->fuzz2(_a0, _a1);
        var_6 = var_5;
    } // end shim_1

    ...

    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_33->fuzz1(_a0);
        var_34 = var_33;
    } // end shim_0
    Test *var_35;
    { // begin shim_0
    int _a0[4] = {0, 0, 3, 0};
        var_34->fuzz1(_a0);
        var_35 = var_34;
    } // end shim_0
    Test *var_36;
    { // begin shim_0
    int _a0[4] = {0, 0, 0, 0};
        var_35->fuzz1(_a0);
        var_36 = var_35;
    } // end shim_0
    { // begin shim_3
        free(var_36);
    } // end shim_3
}
```

5. (optional) Use the `gfuzz` tool to perform graph-aware test case minimization:

```console
$ gfuzz min ./fuzz_exec ./crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53

Minimizing ./crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53...
Base case size: 2058
---[Crash]---
libFuzzer: deadly signal
-------------
Minimizing...
[3] Found smaller crash: 2026
[7] Found smaller crash: 1994
[8] Found smaller crash: 678
[9] Found smaller crash: 306
[10] Found smaller crash: 274
[12] Found smaller crash: 242
[13] Found smaller crash: 178
[14] Found smaller crash: 146
[16] Found smaller crash: 114
[17] Found smaller crash: 82
[21] Found smaller crash: 50
No improvement for 50 steps, stopping...
Minimized crash saved to: ./crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53.min
```

```
$ ./fuzz_write crash-23b6ad2375371d36f46f75fa28f297a1b0e84a53.min
...

#include "lib.h"


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)

int main() {
    Test *var_0;
    { // begin shim_2
        var_0 = MAKE(Test);
        Test ref = Test();
        *var_0 = ref;
    } // end shim_2
    Test *var_1;
    { // begin shim_0
    int _a0[4] = {0, 0, 3, 4};
        var_0->fuzz1(_a0);
        var_1 = var_0;
    } // end shim_0
    { // begin shim_3
        free(var_1);
    } // end shim_3
}
```

## Learn More

For help on setting up your first GraphFuzz harness, see [Basic Usage](https://hgarrereyn.github.io/GraphFuzz/#/quick_start/basic_usage).

For some more in-depth examples, see our collection of Dockerized, runnable [Experiments](https://hgarrereyn.github.io/GraphFuzz/#/experiments/overview).
