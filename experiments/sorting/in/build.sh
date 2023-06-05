cd fuzz

# gfuzz gen cpp schema.yaml .

clang++ \
    fuzz_exec.cpp \
    -I../lib -L../lib \
    -lsorting -lgraphfuzz -lprotobuf \
    -fsanitize=fuzzer,address \
    -o fuzz_exec

clang++ \
    fuzz_write.cpp \
    -I../lib -L../lib \
    -lsorting -lgraphfuzz -lprotobuf \
    -fsanitize=fuzzer,address \
    -o fuzz_write