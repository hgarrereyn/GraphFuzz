
# Experiments

We have created a collection of experiments that demonstrate how to use GraphFuzz with toy examples and real open-source projects. The purpose of this section is to demonstrate various features of GraphFuzz in isolation for educational purposes and to demonstrate tips & tricks we learned along the way while trying to apply GraphFuzz to large real-world projects.

All of these experiments are Dockerized and fully reproducable. We provide some helper scripts to quickly build and run the containers. To run an experiment, first build the base GraphFuzz image:

```bash
cd GraphFuzz/experiments
./build base
```

Then build and run any experiment container:

```bash
./build sqlite3
./run sqlite3
```

## Available Experiments

### Examples

| Experiment | Description |
| --- | --- |
| `hello_graphfuzz` | Fuzz a simple C++ API |
| `ex_array_demo` | Demonstrates how to use array argument types |
| `ex_auto_cpp` | Demonstrates how to use the `gfuzz doxygen` tool to automatically generate a schema from C++ source code |

### OSS Paper Benchmarks

In our original paper, we describe the application of GraphFuzz to 5 open-source projects:

| Experiment | Project | Description |
| --- | --- | --- |
| `skia` | https://skia.org/ | Skia is an open-source 2D graphics library developed by Google and used in projects such as Chromium and Android. |
| `rdkit` | https://www.rdkit.org/ | RDKit is an open-source cheminformatics library written in C++. |
| `eigen` | https://eigen.tuxfamily.org/ | Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms. |
| `sqlite3` | https://www.sqlite.org/ | SQLite is a C-language library that implements a fully-featured SQL database engine. |
| `iowow` | https://iowow.io/ | IOWOW is a C11 persistent key/value storage library based on the skip list data structure. |

### Other

| Experiment | Description |
| --- | --- |
| `rdkit_demo` | Simple demo schema for RDKit as shown in our ICSE 2022 presentation |
