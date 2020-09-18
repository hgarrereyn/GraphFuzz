FROM graphfuzz_base

WORKDIR /src
ENV CMAKE_VERSION 3.19.2
RUN apt-get update && apt-get install -y wget sudo && \
    wget https://github.com/Kitware/CMake/releases/download/v$CMAKE_VERSION/cmake-$CMAKE_VERSION-Linux-x86_64.sh && \
    chmod +x cmake-$CMAKE_VERSION-Linux-x86_64.sh && \
    ./cmake-$CMAKE_VERSION-Linux-x86_64.sh --skip-license --prefix="/usr/local" && \
    rm cmake-$CMAKE_VERSION-Linux-x86_64.sh && \
    rm -rf /usr/local/doc/cmake /usr/local/bin/cmake-gui

RUN cd /src && \
    git clone https://github.com/rdkit/rdkit.git && \
    cd rdkit && \
    git checkout 69b143edd059612c2f28ad898fa2d87dc1525e6f

COPY build_rdkit.sh /src/build_rdkit.sh
RUN /src/build_rdkit.sh

RUN cd /src && \
    wget https://github.com/sharkdp/bat/releases/download/v0.20.0/bat-v0.20.0-x86_64-unknown-linux-musl.tar.gz && \
    tar xvzf bat-v0.20.0-x86_64-unknown-linux-musl.tar.gz && \
    cp bat-v0.20.0-x86_64-unknown-linux-musl/bat /usr/local/bin/bat

COPY in /harness/in
WORKDIR /harness/in

env ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
env ASAN_OPTIONS=detect_leaks=0,allocator_may_return_null=1
