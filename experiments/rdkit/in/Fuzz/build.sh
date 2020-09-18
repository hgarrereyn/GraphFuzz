
export BOOSTHOME=/src/boost_1_69_0/boost
export RDBASE=/src/rdkit

export CPPFLAGS="-I${BOOSTHOME} -I${RDBASE}/Code -fsanitize=address"

export LDFLAGS="-L${RDBASE}/build/lib -Wl,-rpath,${RDBASE}/build/lib -lRDKitAbbreviations -lRDKitForceFieldHelpers -lRDKitRDStreams -lRDKitAlignment -lRDKitFragCatalog -lRDKitRGroupDecomposition -lRDKitCIPLabeler -lRDKitGraphMol -lRDKitReducedGraphs -lRDKitCatalogs -lRDKitInfoTheory -lRDKitRingDecomposerLib -lRDKitChemReactions -lRDKitMMPA -lRDKitScaffoldNetwork -lRDKitChemTransforms -lRDKitMolAlign -lRDKitShapeHelpers -lRDKitChemicalFeatures -lRDKitMolCatalog -lRDKitSimDivPickers -lRDKitDataStructs -lRDKitMolChemicalFeatures -lRDKitSmilesParse -lRDKitDepictor -lRDKitMolDraw2D -lRDKitSubgraphs -lRDKitDeprotect -lRDKitMolEnumerator -lRDKitSubstructLibrary -lRDKitDescriptors -lRDKitMolHash -lRDKitSubstructMatch -lRDKitDistGeomHelpers -lRDKitMolInterchange -lRDKitTautomerQuery -lRDKitDistGeometry -lRDKitMolStandardize -lRDKitTrajectory -lRDKitEigenSolvers -lRDKitMolTransforms -lRDKitcoordgen -lRDKitFMCS -lRDKitO3AAlign -lRDKitga -lRDKitFileParsers -lRDKitOptimizer -lRDKithc -lRDKitFilterCatalog -lRDKitPartialCharges -lRDKitmaeparser -lRDKitFingerprints -lRDKitRDGeneral -lRDKitForceField -lRDKitRDGeometryLib"

export CXX="clang++-10"

echo "[*] Building proto..."
(cd /harness/graphfuzz/src/ && \
    protoc --cpp_out=. graph.proto)

echo "[*] Building executor..."
$CXX -g -c ${CPPFLAGS} -fsanitize=address fuzz_exec.cpp

echo "[*] Building writer..."
$CXX -g -c ${CPPFLAGS} -fsanitize=address fuzz_write.cpp

echo "[*] Building graphfuzz..."
$CXX -g -c /harness/graphfuzz/src/harness.cpp -DTRACE_MUTATIONS
$CXX -g -c /harness/graphfuzz/src/graph.pb.cc

echo "[*] Linking graphfuzz executor..."
$CXX -g harness.o graph.pb.o fuzz_exec.o \
    -fsanitize=address,fuzzer \
    -lprotobuf -lssl -lcrypto ${LDFLAGS} \
    -o fuzz_exec

echo "[*] Linking graphfuzz writer..."
$CXX -g harness.o graph.pb.o fuzz_write.o \
    -fsanitize=address,fuzzer \
    -lprotobuf -lssl -lcrypto ${LDFLAGS} \
    -o fuzz_write
