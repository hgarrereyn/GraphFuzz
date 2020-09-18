
cd $1

./build.sh

mkdir -p corpus
mkdir -p artifacts

./fuzz_exec \
    --graphfuzz_trace_mutations \
    ./corpus \
    -artifact_prefix='./artifacts/' \
    -fork=$2 \
    --graphfuzz_catch=6 \
    -ignore_crashes=1
