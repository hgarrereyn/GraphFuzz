
cd fuzz

clang++ \
    fuzz_exec.cpp \
    -I../lib -L../lib \
    -ltest -lgraphfuzz -lprotobuf \
    -fsanitize=fuzzer,address \
    -o fuzz_exec

clang++ \
    fuzz_write.cpp \
    -I../lib -L../lib \
    -ltest -lgraphfuzz -lprotobuf \
    -fsanitize=fuzzer,address \
    -o fuzz_write
