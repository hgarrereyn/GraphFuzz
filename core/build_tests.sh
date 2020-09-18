
clang++ -o schemaTest \
    schemaTest.cpp \
    -pthread \
    -lgtest

clang++ -o graphTest \
    graphTest.cpp \
    graph.pb.cc \
    -pthread \
    -lprotobuf \
    -lgtest
