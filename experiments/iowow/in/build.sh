# Usage: ./build.sh <fuzzer>

echo "Building $1 exec..."
clang++-10 -g \
    $1/fuzz_exec.cpp \
    -I. \
    -fsanitize=fuzzer,address \
    -liowow -lgraphfuzz -lprotobuf \
    -o $1/fuzz_exec

echo "Building $1 write..."
clang++-10 \
    $1/fuzz_write.cpp \
    -I. \
    -fsanitize=fuzzer,address \
    -liowow -lgraphfuzz -lprotobuf \
    -o $1/fuzz_write
