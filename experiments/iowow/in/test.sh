
./build.sh f1

cd f1 && \
mkdir artifacts && \
./fuzz_exec -fork=32 -ignore_crashes=1 -artifact_prefix="./artifacts/"
