
gfuzz gen cpp schema.yaml .

clang++-10 \
    -o fuzz_exec \
    fuzz_exec.cpp \
    -fsanitize=fuzzer \
    -lprotobuf -lgraphfuzz

clang++-10 \
    -o fuzz_write \
    fuzz_write.cpp \
    -fsanitize=fuzzer \
    -lprotobuf -lgraphfuzz
