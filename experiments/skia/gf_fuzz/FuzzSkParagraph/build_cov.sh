
export CXXFLAGS="\
    -std=c++17 \
    -fvisibility-inlines-hidden \
    -stdlib=libc++ \
    -fno-exceptions \
    -Wnon-virtual-dtor \
    -Wno-noexcept-type \
    -Wno-redundant-move \
    -Wno-abstract-vbase-init \
    -Wno-weak-vtables \
    -Wno-c++98-compat \
    -Wno-c++98-compat-pedantic \
    -Wno-undefined-func-template"

export CXX="/root/clang/bin/clang++"

echo "[*] Building proto..."
(cd /harness/graphfuzz/src/ && \
    protoc --cpp_out=. graph.proto)

echo "[*] Building executor..."
$CXX fuzz_exec.cpp \
    /src/skia/tools/Resources.cpp \
    /src/skia/tools/flags/CommandLineFlags.cpp \
    --coverage \
    -fno-inline \
    -ferror-limit=0 \
    ${CXXFLAGS} \
    -fPIC -shared \
    -I /src/skia/ \
    -I /src/skia/include/ \
    -I /src/skia/src/core \
    -I /src/skia/include/config \
    -I /src/skia/include/gpu \
    -I /src/skia/include/core \
    -I /src/skia/include/effects \
    -I /src/skia/include/pathops \
    -L /src/skia/out/cov_full -lskia -lskparagraph -lskshaper \
    -Wl,-rpath,/src/skia/out/cov_full \
    -fsanitize=fuzzer-no-link \
    -pthread -g \
    -o libfuzzexeccov.so

echo "[*] Building graphfuzz..."
$CXX -g -c /harness/graphfuzz/src/harness.cpp
$CXX -g -c /harness/graphfuzz/src/graph.pb.cc

echo "[*] Linking graphfuzz executor..."
$CXX -g harness.o graph.pb.o \
    -std=c++17 \
    -fno-inline \
    -fsanitize=fuzzer -fsanitize=address \
    -lprotobuf -lfreetype -lfontconfig -lGL \
    -L/root/clang/lib/ -lc++ \
    -Wl,-rpath,/root/clang/lib/ \
    -L. -lfuzzexeccov \
    -Wl,-rpath,. \
    -o fuzz_exec_cov
