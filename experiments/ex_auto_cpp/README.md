
# Auto C++ example

This folder contains an example of using the gfuzz doxygen extractor to automatically generate a C++ schema.

# Overview

(Note: make sure `gfuzz` (`graphfuzz/python/gfuzz`) is on your PATH.)

Run the doxygen extractor with:

```sh
$ gfuzz doxygen --inputs ./in/src --output ./in/doxygen_output
```

This step will launch a new docker container with doxygen and set up the proper Doxyfile to parse the target. The output xml will be saved to `./in/doxygen_output/xml`.

Next, we can automatically infer the schema with:

```sh
$ gfuzz schema infer ./in/doxygen_output/xml ./in/auto_schema.yaml
```

Finally, we can generate the harness files with:

```
$ gfuzz gen cpp ./in/auto_schema.yaml ./in/
```

---

Build and launch the docker container with:
```sh
$ cd graphfuzz/examples/auto_cpp
$ gfuzz run .
```

Inside the container, build the fuzzers (`fuzz_exec`, `fuzz_write`) with:
```sh
$ ./build_fuzzer.sh
```

You can fuzz with the libFuzzer binary `fuzz_exec`:
```sh
$ ./fuzz_exec -fork=10 ... <standard libFuzzer args>
```

Once you have a crash, you can view it with `fuzz_write`:
```sh
$ ./fuzz_write ./crash-xxx
```

You can also minimize the crash with:
```sh
$ gfuzz min ./fuzz_exec ./crash-xxx
```

# Handling `assert()`'s

In this example, `Rect::setVal(float)` will throw assertion errors on invalid arguments which is a common pattern for safe C++ code. In this case, we don't care about these assertion errors.

To bypass this, you can supply a list of signal numbers that should be ignored with `--graphfuzz_catch`. For example, to catch SIGABRT (raised by `assert()`), we can run the fuzzer like:

```sh
$ ./fuzz_exec --graphfuzz_catch=6
```

In this mode, GraphFuzz will catch the error and cleanly exit the test case. However, this raises a new problem: we will suddenly hit a lot of memory leaks which triggers AddressSanitizer. To turn of leak detection, we can set `ASAN_OPTIONS` to `detect_leaks=0`, for example:

```sh
$ ASAN_OPTIONS=detect_leaks=0 ./fuzz_exec --graphfuzz_catch=6
```
