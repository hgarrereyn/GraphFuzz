# Usage: ./build.sh <fuzzer>

echo "Building $1 exec..."
clang++-10 -g \
    $1/fuzz_exec.cpp \
    -x c sqlite3.c \
    -I. \
    -fsanitize=fuzzer,address \
    -ldl -lpthread -lgraphfuzz -lprotobuf \
    -o $1/fuzz_exec

echo "Building $1 write..."
clang++-10 \
    $1/fuzz_write.cpp \
    -x c sqlite3.c \
    -I. \
    -fsanitize=fuzzer,address \
    -ldl -lpthread -lgraphfuzz -lprotobuf \
    -o $1/fuzz_write
