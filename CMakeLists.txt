cmake_minimum_required(VERSION 3.10)
project(GraphFuzz VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIRS}) 
include_directories(${CMAKE_CURRENT_BINARY_DIR}) 

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS core/graph.proto) 

add_library(graphfuzz STATIC
    core/harness.cpp
    core/graph.proto ${PROTO_SRCS} ${PROTO_HDRS}
)

install(
    TARGETS graphfuzz
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
