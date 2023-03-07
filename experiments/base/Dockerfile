FROM ubuntu:18.04
ENV TERM xterm-256color

RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get -y install \
    clang make cmake git wget curl tar gdb vim \
    python3.8 python3-pip libprotobuf-dev protobuf-compiler

# Install poetry
RUN python3.8 -m pip install poetry

WORKDIR /graphfuzz
COPY cli /graphfuzz/cli
COPY core /graphfuzz/core
COPY CMakeLists.txt /graphfuzz/CMakeLists.txt

# Build and install libgraphfuzz
RUN cd /graphfuzz && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

# Install gfuzz python tool
RUN cd /graphfuzz/cli && \
    poetry build && \
    poetry export > dist/requirements.txt && \
    python3.8 -m pip install -r dist/requirements.txt && \
    python3.8 -m pip install ./dist/gfuzz-*.whl
