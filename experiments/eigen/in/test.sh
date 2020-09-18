./build.sh f1

cd f1 && \
mkdir -p artifacts && mkdir -p corpus && \
./fuzz_exec --graphfuzz_init_corpus ./corpus && \
./fuzz_exec ./corpus --graphfuzz_catch=6 -fork=32 -ignore_crashes=1 -artifact_prefix="./artifacts/"
