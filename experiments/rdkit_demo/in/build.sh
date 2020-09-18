
gfuzz gen cpp schema.yaml .

source ./set_flags.sh

clang++ fuzz_exec.cpp -o fuzz_exec ${CPPFLAGS} ${LDFLAGS} -fsanitize=address,fuzzer -lgraphfuzz -lprotobuf

clang++ fuzz_write.cpp -o fuzz_write ${CPPFLAGS} ${LDFLAGS} -fsanitize=address,fuzzer -lgraphfuzz -lprotobuf
