
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
    -L /src/skia/out/full -lskia -lskparagraph -lskshaper \
    -Wl,-rpath,/src/skia/out/full \
    -fsanitize=fuzzer-no-link \
    -pthread -g \
    -o libfuzzexec.so

echo "[*] Building writer..."
$CXX fuzz_write.cpp \
    -fPIC -shared \
    -I /src/skia/ \
    -I /src/skia/include/ \
    -I /src/skia/src/core \
    -I /src/skia/include/config \
    -I /src/skia/include/gpu \
    -I /src/skia/include/core \
    -I /src/skia/include/effects \
    -I /src/skia/include/pathops \
    -L /src/skia/out/full -lskia \
    -Wl,-rpath,/src/skia/out/full \
    -pthread -g \
    -o libfuzzwrite.so

echo "[*] Building graphfuzz..."
$CXX -g -c /harness/graphfuzz/src/harness.cpp -DTRACE_MUTATIONS
$CXX -g -c /harness/graphfuzz/src/graph.pb.cc

echo "[*] Linking graphfuzz executor..."
$CXX -g harness.o graph.pb.o \
    -std=c++17 \
    -fsanitize=fuzzer -fsanitize=address \
    -lprotobuf -lfontconfig -lGL \
    -lssl -lcrypto \
    -L/root/clang/lib/ -lc++ \
    -Wl,-rpath,/root/clang/lib/ \
    -L. -lfuzzexec \
    -Wl,-rpath,. \
    -o fuzz_exec

echo "[*] Linking graphfuzz writer..."
$CXX -g harness.o graph.pb.o \
    -fsanitize=fuzzer -fsanitize=address \
    -lprotobuf -lfontconfig -lGL \
    -lssl -lcrypto \
    -L/root/clang/lib/ -lc++ \
    -Wl,-rpath,/root/clang/lib/ \
    -L. -lfuzzwrite \
    -Wl,-rpath,. \
    -o fuzz_write
