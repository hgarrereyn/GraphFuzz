
# Auto C++ example

This folder contains an example of using the gfuzz doxygen extractor to automatically generate a C++ schema.

# Overview

_Note: schema inferrence with Doxygen is still very experimental._

This example contains a simple mock-graphics API in `./in/lib`. We can use the `gfuzz doxygen` command to run `doxygen` on this source code and produce nice parseable xml with all of the identified C++ structs/types/enums. Then we can use `gfuzz schema infer` to convert this xml into the GraphFuzz YAML schema format and automatically build a fuzzer.

To run this example (context: `GraphFuzz/examples`):
1. Install the `gfuzz` cli and run `./ex_auto_cpp/make_schema.sh` to:
    - Run `doxygen` in a docker container to produce xml
    - Convert the xml into a harness schema
    - Generate C++ source files from the harness schema
2. Build and launch the docker container with: `./build ex_auto_cpp && ./run ex_auto_cpp`
3. Inside the container run `cd fuzz && ./fuzz_exec` to start the fuzzer.

# Details

Here are the steps that `./make_schema.sh` performs:

Run the doxygen extractor with:

```sh
$ gfuzz doxygen --inputs ./in/lib --output ./in/doxygen_output
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

# Practicality

It isn't always possible to infer correct usage of an endpoint with this kind of approach. For example, endpoints like `void doThing(void *p)` or `void process(int arr[], int size)` require further clarification:

- what does `void *p` point to? Can it be null?
- is `int arr[]` an input or an output?
- does `size` correlate with the size of `arr`?

In practice, we find that automatically generating schemas with this tool can be a useful first step to building a harness but unless you are working with toy examples (like this) you will likely need manual revision.
