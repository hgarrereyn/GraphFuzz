
# Installation

## Package managers

TODO

## Build from source:

Clone the repository:

```bash
git clone https://github.com/ForAllSecure/GraphFuzz.git
```

### 1. `libgraphfuzz`

`libgraphfuzz` is the runtime graph mutation library that is linked into your fuzzer harness. It is written in C++ and uses a standard CMake build configuration:

```bash
cd GraphFuzz
mkdir build
cd build
cmake ..
make
make install
```

### 2. `gfuzz`

`gfuzz` is a Python command-line tool that builds harness files and performs miscellaneous other functions like graph minimization. It is written in Python and uses the Poetry build system:

```bash
cd GraphFuzz/cli
poetry build
poetry export > dist/requirements.txt
python3 -m pip install -r dist/requirements.txt
python3 -m pip install ./dist/gfuzz-*.whl
```
