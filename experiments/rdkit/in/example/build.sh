
export BOOSTHOME=/src/boost_1_69_0/boost
export RDBASE=/src/rdkit

export CPPFLAGS="-I${BOOSTHOME} -I${RDBASE}/Code -fsanitize=address"

export LDFLAGS="-L${RDBASE}/build/lib -Wl,-rpath,${RDBASE}/build/lib -lRDKitAbbreviations -lRDKitForceFieldHelpers -lRDKitRDStreams -lRDKitAlignment -lRDKitFragCatalog -lRDKitRGroupDecomposition -lRDKitCIPLabeler -lRDKitGraphMol -lRDKitReducedGraphs -lRDKitCatalogs -lRDKitInfoTheory -lRDKitRingDecomposerLib -lRDKitChemReactions -lRDKitMMPA -lRDKitScaffoldNetwork -lRDKitChemTransforms -lRDKitMolAlign -lRDKitShapeHelpers -lRDKitChemicalFeatures -lRDKitMolCatalog -lRDKitSimDivPickers -lRDKitDataStructs -lRDKitMolChemicalFeatures -lRDKitSmilesParse -lRDKitDepictor -lRDKitMolDraw2D -lRDKitSubgraphs -lRDKitDeprotect -lRDKitMolEnumerator -lRDKitSubstructLibrary -lRDKitDescriptors -lRDKitMolHash -lRDKitSubstructMatch -lRDKitDistGeomHelpers -lRDKitMolInterchange -lRDKitTautomerQuery -lRDKitDistGeometry -lRDKitMolStandardize -lRDKitTrajectory -lRDKitEigenSolvers -lRDKitMolTransforms -lRDKitcoordgen -lRDKitFMCS -lRDKitO3AAlign -lRDKitga -lRDKitFileParsers -lRDKitOptimizer -lRDKithc -lRDKitFilterCatalog -lRDKitPartialCharges -lRDKitmaeparser -lRDKitFingerprints -lRDKitRDGeneral -lRDKitForceField -lRDKitRDGeometryLib"

clang++ -g \
    ${CPPFLAGS} ${LDFLAGS} \
    -o test \
    test.cpp
