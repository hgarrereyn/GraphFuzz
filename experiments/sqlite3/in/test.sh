
./build.sh f1

cd f1 && \
mkdir corpus && \
./fuzz_exec --graphfuzz_init_corpus ./corpus && \
./fuzz_exec ./corpus -fork=32 -dict=../sql.dict -ignore_crashes=1
