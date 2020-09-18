export CXX="/root/clang/bin/clang++"


echo "[*] Reset build tree..."
rm -rf /src/skia/graphfuzz
mkdir /src/skia/graphfuzz

echo "[*] Copy harness files..."
cp /harness/in/FuzzCanvas/api_mock_gpu_canvas/fuzz_exec.cpp /src/skia/graphfuzz

echo "[*] replace BUILD.gn ..."
cp /harness/in/FuzzCanvas/api_mock_gpu_canvas/BUILD.gn /src/skia/BUILD.gn

echo "[*] Building new targets using Skia build system..."
cd /src/skia
ninja -C out/full \
    gf_mock_gpu_exec

echo "[*] (cov) Building new targets using Skia build system..."
cd /src/skia
ninja -C out/cov_full \
    gf_mock_gpu_exec

echo "[*] Building proto..."
(cd /harness/graphfuzz/src/ && \
    protoc --cpp_out=. graph.proto)

cd /harness/in/FuzzCanvas/api_mock_gpu_canvas

echo "[*] Building graphfuzz..."
$CXX -g -c /harness/graphfuzz/src/harness.cpp
$CXX -g -c /harness/graphfuzz/src/graph.pb.cc

echo "[*] Linking graphfuzz executor..."
$CXX -g harness.o graph.pb.o \
    -fsanitize=fuzzer,address \
    -lprotobuf \
    -L/src/skia/out/full -lgf_mock_gpu_exec \
    -Wl,-rpath,/src/skia/out/full \
    -o fuzz_exec

echo "[*] Linking graphfuzz writer..."
$CXX -g fuzz_write.cpp harness.o graph.pb.o \
    -fsanitize=fuzzer,address \
    -lprotobuf \
    -o fuzz_write

echo "[*] (cov) Linking graphfuzz executor..."
$CXX -g harness.o graph.pb.o \
    -fsanitize=fuzzer,address \
    -lprotobuf \
    -L/src/skia/out/cov_full -lgf_mock_gpu_exec \
    -Wl,-rpath,/src/skia/out/cov_full \
    -o fuzz_exec_cov
