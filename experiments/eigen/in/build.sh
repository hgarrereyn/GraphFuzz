# Usage: ./build.sh <fuzzer>

echo "Building $1 exec..."
clang++-10 -g \
    -std=c++17 \
    $1/fuzz_exec.cpp \
    -I/src/eigen \
    -fsanitize=fuzzer,address \
    -lgraphfuzz -lprotobuf \
    -o $1/fuzz_exec

echo "Building $1 write..."
clang++-10 \
    -std=c++17 \
    $1/fuzz_write.cpp \
    -I/src/eigen \
    -fsanitize=fuzzer,address \
    -lgraphfuzz -lprotobuf \
    -o $1/fuzz_write
