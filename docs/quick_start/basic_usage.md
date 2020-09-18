
# Basic Usage

> Follow along with the `hello_graphfuzz` experiment. See [experiments/overview.md](experiments/overview.md) for instructions.

Here is a simple C++ target:

**lib.h**
```cpp
#include <cstring>
#include <vector>

class Foo {
public:
    Foo(): buffer(0) {}

    void write(char val) {
        buffer.push_back(val);
    }

    void check() {
        if (buffer.size() >= 4 && \
            buffer[0] == 'F' && \
            buffer[1] == 'U' && \
            buffer[2] == 'Z' && \
            buffer[3] == 'Z'
        ) {
            __builtin_trap();
        }
    }
private:
    std::vector<char> buffer;
};
```

In this target, there is no single function that works with a standard `LLVMFuzzerTestOneInput`-type harness. However you could do something like the following to build a de-facto API fuzzer:

```cpp
int LLVMFuzzerTestOneInput(const char *Data, size_t Size) {
    Foo foo;
    for (int i = 0; i < Size; ++i) {
        foo.write(Data[i]);
    }
    foo.check();
}
```

This type of harness construction requires some domain knowlege about the API and already imposes several constraints on the fuzzer search space. For example, what if a bug requires calling `Foo::write` after `Foo::check` or calling `Foo::check` multiple times? We will never hit those bugs with this fuzzer harness and instead, we might get a false sense of security because we have "full coverage." As the API surface grows larger, the number of ways in which functions can interact grows exponentially and it becomes even harder to generate these "de-facto" harnesses.

With GraphFuzz, a driving vision is to let the fuzzer engine discover the API usage pattern on its own through coverage-guided mutation. Rather than imposing our own developer-driven constraints on how to fuzz several API functions, we define a `schema` that describes all of the API endpoints we want to fuzz and let the fuzzer construct test cases. A GraphFuzz schema for the library above would look like this:

**schema.yaml**
```yaml
Foo:
  type: struct
  name: Foo
  headers: [lib.h]
  methods:
  - Foo()
  - ~Foo()
  - void write(char val)
  - void check()
```

This schema describes a library API with one object: `struct Foo` and four endpoints:
- `Foo::Foo()` (a constructor)
- `Foo::~Foo()` (a destructor)
- `Foo::write(char)`
- `Foo::check()`

Notice that in this schema, we are only providing GraphFuzz with the function signature. Behind the scenes, GraphFuzz attemts to infer the semantics (i.e. that `Foo::Foo` is a constructor and not a method call). In most cases, this inference is perfect; however, we do encounter functions with implicit constraints on arguments or nonstandard API constructions. Therefore, GraphFuzz also supports a more verbose, flexible endpoint declaration called a custom endpoint. See our tutorial on [Custom Endpoints](quick_start/custom_endpoints.md).

Next, we use the `gfuzz` tool to synthesize our actual C++ harness files:

```bash
# Usage: gfuzz gen [lang] [schema] [output directory]
$ gfuzz gen cpp schema.yaml .
```

This will result in 3 files:
- `fuzz_exec.cpp`: Our main fuzzer harness.
- `fuzz_write.cpp`: A mirror harness used to convert dataflow graphs to source code.
- `schema.json`: Type metadata that is used by GraphFuzz at runtime.

Finally, we compile our fuzzer harness as any other libFuzzer harness:

```bash
clang++ \
    -o fuzz_exec \
    fuzz_exec.cpp \
    -fsanitize=fuzzer \
    -lprotobuf -lgraphfuzz
```

Now we can run the fuzzer! Note that GraphFuzz uses libFuzzer under the hood and as such we can include libFuzzer features like `user_value_profile`, `fork`, `dict` etc...

```
$ ./fuzz_exec -use_value_profile=1

[*] Loading: schema.json
[*] GraphFuzz: loading trees from cache...
[*] After validation: total scopes: 4
[*] After validation: usable scopes: 4
INFO: Seed: 3064788795
INFO: Loaded 1 modules   (155 inline 8-bit counters): 155 [0x78d440, 0x78d4db),
INFO: Loaded 1 PC tables (155 PCs): 155 [0x536e60,0x537810),
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: A corpus is not provided, starting from an empty corpus
#2	INITED cov: 8 ft: 11 corp: 1/1b exec/s: 0 rss: 26Mb
	NEW_FUNC[1/51]: 0x4b5e30 in shim_finalize (/harness/in/fuzz_exec+0x4b5e30)
	NEW_FUNC[2/51]: 0x4b5e50 in shim_0 (/harness/in/fuzz_exec+0x4b5e50)
#3	NEW    cov: 73 ft: 104 corp: 2/40b lim: 4096 exec/s: 0 rss: 29Mb L: 39/39 MS: 1 Custom-
#5	NEW    cov: 73 ft: 110 corp: 3/86b lim: 4096 exec/s: 0 rss: 29Mb L: 46/46 MS: 2 Custom-CustomCrossOver-
#10	NEW    cov: 73 ft: 119 corp: 4/148b lim: 4096 exec/s: 0 rss: 29Mb L: 62/62 MS: 5 Custom-Custom-CustomCrossOver-CustomCrossOver-CustomCrossOver-
	NEW_FUNC[1/24]: 0x4b6180 in shim_2 (/harness/in/fuzz_exec+0x4b6180)
	NEW_FUNC[2/24]: 0x4b6220 in Foo::write(char) (/harness/in/fuzz_exec+0x4b6220)
#16	NEW    cov: 104 ft: 177 corp: 5/190b lim: 4096 exec/s: 0 rss: 29Mb L: 42/62 MS: 1 CustomCrossOver-
#17	NEW    cov: 104 ft: 181 corp: 6/206b lim: 4096 exec/s: 0 rss: 29Mb L: 16/62 MS: 1 CustomCrossOver-
#22	NEW    cov: 104 ft: 191 corp: 7/286b lim: 4096 exec/s: 0 rss: 29Mb L: 80/80 MS: 5 CustomCrossOver-Custom-Custom-CustomCrossOver-CustomCrossOver-
#67	NEW    cov: 104 ft: 193 corp: 8/398b lim: 4096 exec/s: 0 rss: 29Mb L: 112/112 MS: 5 Custom-CustomCrossOver-Custom-Custom-CustomCrossOver-
#69	NEW    cov: 104 ft: 196 corp: 9/526b lim: 4096 exec/s: 0 rss: 29Mb L: 128/128 MS: 2 Custom-CustomCrossOver-
#84	NEW    cov: 104 ft: 200 corp: 10/702b lim: 4096 exec/s: 0 rss: 29Mb L: 176/176 MS: 8 CrossOver-Custom-ChangeByte-Custom-ChangeBinInt-Custom-CustomCrossOver-CustomCrossOver-
#91	NEW    cov: 104 ft: 201 corp: 11/846b lim: 4096 exec/s: 0 rss: 29Mb L: 144/176 MS: 2 Custom-CustomCrossOver-
#113	NEW    cov: 104 ft: 203 corp: 12/895b lim: 4096 exec/s: 0 rss: 29Mb L: 49/176 MS: 3 ChangeByte-Custom-CustomCrossOver-
#134	NEW    cov: 104 ft: 204 corp: 13/1087b lim: 4096 exec/s: 0 rss: 29Mb L: 192/192 MS: 1 CustomCrossOver-
#163	NEW    cov: 106 ft: 251 corp: 14/1139b lim: 4096 exec/s: 0 rss: 29Mb L: 52/192 MS: 7 ChangeBit-Custom-ChangeBit-Custom-ChangeBit-Custom-CustomCrossOver-
#173	NEW    cov: 106 ft: 283 corp: 15/1212b lim: 4096 exec/s: 0 rss: 29Mb L: 73/192 MS: 6 CustomCrossOver-Custom-CustomCrossOver-ShuffleBytes-Custom-CustomCrossOver-
#179	NEW    cov: 106 ft: 293 corp: 16/1468b lim: 4096 exec/s: 0 rss: 29Mb L: 256/256 MS: 1 CustomCrossOver-
#180	NEW    cov: 106 ft: 297 corp: 17/1756b lim: 4096 exec/s: 0 rss: 29Mb L: 288/288 MS: 1 CustomCrossOver-
#215	NEW    cov: 107 ft: 303 corp: 18/1848b lim: 4096 exec/s: 0 rss: 29Mb L: 92/288 MS: 9 ShuffleBytes-Custom-ChangeBit-Custom-ChangeByte-Custom-ChangeBinInt-Custom-CustomCrossOver-
#223	REDUCE cov: 107 ft: 303 corp: 18/1825b lim: 4096 exec/s: 0 rss: 29Mb L: 121/288 MS: 3 Custom-Custom-CustomCrossOver-
#225	NEW    cov: 107 ft: 305 corp: 19/1912b lim: 4096 exec/s: 0 rss: 29Mb L: 87/288 MS: 3 ShuffleBytes-Custom-CustomCrossOver-
	NEW_FUNC[1/1]: 0x4b96d0 in std::vector<char, std::allocator<char> >::operator[](unsigned long) (/harness/in/fuzz_exec+0x4b96d0)
#231	NEW    cov: 109 ft: 341 corp: 20/2039b lim: 4096 exec/s: 0 rss: 29Mb L: 127/288 MS: 1 CustomCrossOver-

...

#52190	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1535 rss: 32Mb L: 242/4060 MS: 3 CopyPart-Custom-Custom-
#52223	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1535 rss: 32Mb L: 795/4060 MS: 5 ShuffleBytes-Custom-ChangeByte-Custom-CustomCrossOver-
#52268	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1537 rss: 32Mb L: 363/4060 MS: 8 CustomCrossOver-ShuffleBytes-Custom-CrossOver-Custom-CopyPart-Custom-CustomCrossOver-
#52329	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1539 rss: 32Mb L: 2214/4060 MS: 1 CustomCrossOver-
#52620	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1547 rss: 32Mb L: 207/4060 MS: 1 Custom-
#53027	REDUCE cov: 112 ft: 597 corp: 142/82Kb lim: 4096 exec/s: 1559 rss: 32Mb L: 172/4060 MS: 2 CustomCrossOver-CustomCrossOver-
#53449	NEW    cov: 112 ft: 598 corp: 143/82Kb lim: 4096 exec/s: 1527 rss: 32Mb L: 229/4060 MS: 2 CustomCrossOver-CustomCrossOver-
#53595	REDUCE cov: 112 ft: 598 corp: 143/82Kb lim: 4096 exec/s: 1531 rss: 32Mb L: 106/4060 MS: 1 CustomCrossOver-
#53621	REDUCE cov: 112 ft: 598 corp: 143/82Kb lim: 4096 exec/s: 1532 rss: 32Mb L: 720/4060 MS: 1 Custom-
#53728	REDUCE cov: 112 ft: 598 corp: 143/82Kb lim: 4096 exec/s: 1535 rss: 32Mb L: 245/4060 MS: 3 CrossOver-Custom-Custom-
#53729	REDUCE cov: 112 ft: 598 corp: 143/82Kb lim: 4096 exec/s: 1535 rss: 32Mb L: 245/4060 MS: 1 CustomCrossOver-
#54115	REDUCE cov: 112 ft: 598 corp: 143/81Kb lim: 4096 exec/s: 1546 rss: 32Mb L: 1281/4060 MS: 1 CustomCrossOver-
#54329	REDUCE cov: 112 ft: 598 corp: 143/81Kb lim: 4096 exec/s: 1552 rss: 32Mb L: 156/4060 MS: 7 CopyPart-Custom-ChangeBit-Custom-ChangeBit-Custom-CustomCrossOver-
#54396	NEW    cov: 112 ft: 599 corp: 144/82Kb lim: 4096 exec/s: 1554 rss: 32Mb L: 953/4060 MS: 3 ShuffleBytes-Custom-CustomCrossOver-
#54428	REDUCE cov: 112 ft: 600 corp: 145/82Kb lim: 4096 exec/s: 1555 rss: 32Mb L: 245/4060 MS: 4 ShuffleBytes-Custom-ChangeByte-Custom-
#54644	REDUCE cov: 112 ft: 600 corp: 145/82Kb lim: 4096 exec/s: 1561 rss: 32Mb L: 755/4060 MS: 1 CustomCrossOver-
==81== ERROR: libFuzzer: deadly signal
    #0 0x4b4640 in __sanitizer_print_stack_trace (/harness/in/fuzz_exec+0x4b4640)
    #1 0x460948 in fuzzer::PrintStackTrace() (/harness/in/fuzz_exec+0x460948)
    #2 0x445a93 in fuzzer::Fuzzer::CrashCallback() (/harness/in/fuzz_exec+0x445a93)
    #3 0x7f9b3db7597f  (/lib/x86_64-linux-gnu/libpthread.so.0+0x1297f)
    #4 0x4b64d2 in Foo::check() (/harness/in/fuzz_exec+0x4b64d2)
    #5 0x4b6307 in shim_3 (/harness/in/fuzz_exec+0x4b6307)
    #6 0x4bc601 in LLVMFuzzerTestOneInput (/harness/in/fuzz_exec+0x4bc601)
    #7 0x447151 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/harness/in/fuzz_exec+0x447151)
    #8 0x446895 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool*) (/harness/in/fuzz_exec+0x446895)
    #9 0x448b37 in fuzzer::Fuzzer::MutateAndTestOne() (/harness/in/fuzz_exec+0x448b37)
    #10 0x449835 in fuzzer::Fuzzer::Loop(std::__Fuzzer::vector<fuzzer::SizedFile, fuzzer::fuzzer_allocator<fuzzer::SizedFile> >&) (/harness/in/fuzz_exec+0x449835)
    #11 0x4381ee in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/harness/in/fuzz_exec+0x4381ee)
    #12 0x461032 in main (/harness/in/fuzz_exec+0x461032)
    #13 0x7f9b3d16fbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #14 0x40cf89 in _start (/harness/in/fuzz_exec+0x40cf89)

NOTE: libFuzzer has rudimentary signal handlers.
      Combine libFuzzer with AddressSanitizer or similar for better crash reports.
SUMMARY: libFuzzer: deadly signal
MS: 6 ShuffleBytes-Custom-CustomCrossOver-CopyPart-Custom-CustomCrossOver-; base unit: 12617bb03152ce6c11a9e1e981e0de0584a29c98
0xa,0x4,0x2a,0x2,0x8,0x1,0xa,0xf,0x8,0x1,0x10,0x2,0x18,0x1,0x22,0x0,0x2a,0x2,0x8,0x2,0x32,0x1,0x46,0xa,0x11,0x8,0x2,0x10,0x2,0x18,0x2,0x22,0x2,0x8,0x1,0x2a,0x2,0x8,0x3,0x32,0x1,0x55,0xa,0xe,0x8,0x3,0x10,0x3,0x18,0x3,0x22,0x2,0x8,0x2,0x2a,0x2,0x8,0x4,0xa,0xe,0x8,0x4,0x10,0x3,0x18,0x4,0x22,0x2,0x8,0x3,0x2a,0x2,0x8,0x5,0xa,0xe,0x8,0x5,0x10,0x3,0x18,0x5,0x22,0x2,0x8,0x4,0x2a,0x2,0x8,0x6,0xa,0x11,0x8,0x6,0x10,0x2,0x18,0x6,0x22,0x2,0x8,0x5,0x2a,0x2,0x8,0x7,0x32,0x1,0x5a,0xa,0xe,0x8,0x7,0x10,0x3,0x18,0x7,0x22,0x2,0x8,0x6,0x2a,0x2,0x8,0x8,0xa,0xe,0x8,0x8,0x10,0x3,0x18,0x8,0x22,0x2,0x8,0x7,0x2a,0x2,0x8,0x9,0xa,0xe,0x8,0x9,0x10,0x3,0x18,0x9,0x22,0x2,0x8,0x8,0x2a,0x2,0x8,0xa,0xa,0x11,0x8,0xa,0x10,0x2,0x18,0xa,0x22,0x2,0x8,0x9,0x2a,0x2,0x8,0xb,0x32,0x1,0x5a,0xa,0x11,0x8,0xb,0x10,0x2,0x18,0xb,0x22,0x2,0x8,0xa,0x2a,0x2,0x8,0xc,0x32,0x1,0x89,0xa,0x11,0x8,0xc,0x10,0x2,0x18,0xc,0x22,0x2,0x8,0xb,0x2a,0x2,0x8,0xd,0x32,0x1,0xfe,0xa,0xe,0x8,0xd,0x10,0x3,0x18,0xd,0x22,0x2,0x8,0xc,0x2a,0x2,0x8,0xe,0xa,0xa,0x8,0xe,0x10,0x1,0x18,0xe,0x22,0x2,0x8,0xd,
\x0a\x04*\x02\x08\x01\x0a\x0f\x08\x01\x10\x02\x18\x01\"\x00*\x02\x08\x022\x01F\x0a\x11\x08\x02\x10\x02\x18\x02\"\x02\x08\x01*\x02\x08\x032\x01U\x0a\x0e\x08\x03\x10\x03\x18\x03\"\x02\x08\x02*\x02\x08\x04\x0a\x0e\x08\x04\x10\x03\x18\x04\"\x02\x08\x03*\x02\x08\x05\x0a\x0e\x08\x05\x10\x03\x18\x05\"\x02\x08\x04*\x02\x08\x06\x0a\x11\x08\x06\x10\x02\x18\x06\"\x02\x08\x05*\x02\x08\x072\x01Z\x0a\x0e\x08\x07\x10\x03\x18\x07\"\x02\x08\x06*\x02\x08\x08\x0a\x0e\x08\x08\x10\x03\x18\x08\"\x02\x08\x07*\x02\x08\x09\x0a\x0e\x08\x09\x10\x03\x18\x09\"\x02\x08\x08*\x02\x08\x0a\x0a\x11\x08\x0a\x10\x02\x18\x0a\"\x02\x08\x09*\x02\x08\x0b2\x01Z\x0a\x11\x08\x0b\x10\x02\x18\x0b\"\x02\x08\x0a*\x02\x08\x0c2\x01\x89\x0a\x11\x08\x0c\x10\x02\x18\x0c\"\x02\x08\x0b*\x02\x08\x0d2\x01\xfe\x0a\x0e\x08\x0d\x10\x03\x18\x0d\"\x02\x08\x0c*\x02\x08\x0e\x0a\x0a\x08\x0e\x10\x01\x18\x0e\"\x02\x08\x0d
artifact_prefix='./'; Test unit written to ./crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6
```

We found a crash! Each test case file represents a serialized dataflow graph. So if we peek at our crash case it might look a bit opaque:

```console
$ xxd crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6 | head

00000000: 0a04 2a02 0801 0a0f 0801 1002 1801 2200  ..*...........".
00000010: 2a02 0802 3201 460a 1108 0210 0218 0222  *...2.F........"
00000020: 0208 012a 0208 0332 0155 0a0e 0803 1003  ...*...2.U......
00000030: 1803 2202 0802 2a02 0804 0a0e 0804 1003  .."...*.........
00000040: 1804 2202 0803 2a02 0805 0a0e 0805 1003  .."...*.........
00000050: 1805 2202 0804 2a02 0806 0a11 0806 1002  .."...*.........
00000060: 1806 2202 0805 2a02 0807 3201 5a0a 0e08  .."...*...2.Z...
00000070: 0710 0318 0722 0208 062a 0208 080a 0e08  ....."...*......
00000080: 0810 0318 0822 0208 072a 0208 090a 0e08  ....."...*......
00000090: 0910 0318 0922 0208 082a 0208 0a0a 1108  ....."...*......
```

In order to convert this to something human-readable, we can use our `fuzz_write` harness to synthesize source code from the graph:

```bash
clang++ \
    -o fuzz_write \
    fuzz_write.cpp \
    -fsanitize=fuzzer \
    -lprotobuf -lgraphfuzz
```

```bash
$ ./fuzz_write crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6

/* --- boilerplate --- */

int main() {
    Foo *var_0;
    { // begin shim_0
        var_0 = MAKE(Foo);
        Foo ref = Foo();
        *var_0 = ref;
    } // end shim_0
    Foo *var_1;
    { // begin shim_2
        var_0->write(70);
        var_1 = var_0;
    } // end shim_2
    Foo *var_2;
    { // begin shim_2
        var_1->write(85);
        var_2 = var_1;
    } // end shim_2
    Foo *var_3;
    { // begin shim_3
        var_2->check();
        var_3 = var_2;
    } // end shim_3
    Foo *var_4;
    { // begin shim_3
        var_3->check();
        var_4 = var_3;
    } // end shim_3
    Foo *var_5;
    { // begin shim_3
        var_4->check();
        var_5 = var_4;
    } // end shim_3
    Foo *var_6;
    { // begin shim_2
        var_5->write(90);
        var_6 = var_5;
    } // end shim_2
    Foo *var_7;
    { // begin shim_3
        var_6->check();
        var_7 = var_6;
    } // end shim_3
    Foo *var_8;
    { // begin shim_3
        var_7->check();
        var_8 = var_7;
    } // end shim_3
    Foo *var_9;
    { // begin shim_3
        var_8->check();
        var_9 = var_8;
    } // end shim_3
    Foo *var_10;
    { // begin shim_2
        var_9->write(90);
        var_10 = var_9;
    } // end shim_2
    Foo *var_11;
    { // begin shim_2
        var_10->write(-119);
        var_11 = var_10;
    } // end shim_2
    Foo *var_12;
    { // begin shim_2
        var_11->write(-2);
        var_12 = var_11;
    } // end shim_2
    Foo *var_13;
    { // begin shim_3
        var_12->check();
        var_13 = var_12;
    } // end shim_3
    { // begin shim_1
        free(var_13);
    } // end shim_1
}
```

Since this crash is still represented internally as a dataflow graph, we can use the same fuzzer concepts to perform graph-aware minimization.

> Note: Currently libFuzzer doesn't support customization of the `minimize_crash` option which by default tries to perform byte-aware minimization. So we provide a graph-aware minimization utility as part of the `gfuzz` tool.


```bash
# Usage: gfuzz min [fuzzer] [crash]
$ gfuzz min ./fuzz_exec crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6

Minimizing crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6...
Base case size: 242
---[Crash]---
libFuzzer: deadly signal
-------------
Minimizing...
[1] Found smaller crash: 226
[10] Found smaller crash: 207
[13] Found smaller crash: 191
[19] Found smaller crash: 175
[23] Found smaller crash: 159
[30] Found smaller crash: 143
[35] Found smaller crash: 124
[38] Found smaller crash: 108
[46] Found smaller crash: 106
No improvement for 50 steps, stopping...
Minimized crash saved to: crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6.min
```

Now we can view this minimized case:

```console
$ ./fuzz_write crash-2bb07f5f9fbf2d17771d450e9d4d41ba2cf6d8a6.min

/* --- boilerplate --- */

int main() {
    Foo *var_0;
    { // begin shim_0
        var_0 = MAKE(Foo);
        Foo ref = Foo();
        *var_0 = ref;
    } // end shim_0
    Foo *var_1;
    { // begin shim_2
        var_0->write(70);
        var_1 = var_0;
    } // end shim_2
    Foo *var_2;
    { // begin shim_2
        var_1->write(85);
        var_2 = var_1;
    } // end shim_2
    Foo *var_3;
    { // begin shim_2
        var_2->write(90);
        var_3 = var_2;
    } // end shim_2
    Foo *var_4;
    { // begin shim_2
        var_3->write(90);
        var_4 = var_3;
    } // end shim_2
    Foo *var_5;
    { // begin shim_3
        var_4->check();
        var_5 = var_4;
    } // end shim_3
    { // begin shim_1
        free(var_5);
    } // end shim_1
}
```

Much better!
