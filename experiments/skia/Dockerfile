FROM graphfuzz_base

RUN apt-get -y update && apt-get -y install \
    autoconf libtool libc6-dbg \
    ninja-build liblzma-dev libz-dev pkg-config binutils nasm \
    libtool-bin gettext \
    gdb valgrind vim \
    freeglut3-dev \
    libfontconfig-dev \
    libfreetype6-dev \
    libgif-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libharfbuzz-dev \
    libicu-dev \
    libjpeg-dev \
    libpng-dev \
    libwebp-dev \
    python3-lxml doxygen zsh \
    lcov \
    libssl-dev

# Use a pinned version of Skia for experiment reproducability.
# bd816d3c5298f6eada11e18fc9e4ad08214c0dfc: May 14th, 2021
WORKDIR /src
RUN git clone https://github.com/google/skia.git && \
    cd skia && \
    git checkout bd816d3c5298f6eada11e18fc9e4ad08214c0dfc

# Sync Skia dependencies.
WORKDIR /src/skia
RUN python2 tools/git-sync-deps
RUN CLANGDIR="${HOME}/clang" && \
    CC= CXX= infra/bots/assets/clang_linux/create.py -t "$CLANGDIR"

# Build libprotobuf with the Skia toolchain using std=c++17 and the libc++ stdlib.
WORKDIR /src
RUN wget https://github.com/protocolbuffers/protobuf/releases/download/v3.15.8/protobuf-all-3.15.8.tar.gz
RUN tar -xf protobuf-all-3.15.8.tar.gz
WORKDIR /src/protobuf-3.15.8
RUN ./configure CC=/root/clang/bin/clang CXX=/root/clang/bin/clang++ CXXFLAGS="-std=c++17 -stdlib=libc++" LDFLAGS="-stdlib=libc++" prefix=/usr && \
    make -j8 && \
    make install
RUN ldconfig

WORKDIR /src/skia

# We use two builds of Skia:
# - full: ASAN instrumented, with fuzzers
# - cov_full: ASAN instrumented with coverage instrumentation (-fprofile-arcs,-ftest-coverage,--coverage)

# For ease of development, we first build and cache an unmodified version of Skia and then add fuzzer files
# and perform a partial rebuild.

# Build Skia fuzzers with ASAN.
RUN mkdir -p out/full && \
    echo 'cc = "/root/clang/bin/clang"\ncxx = "/root/clang/bin/clang++"\nsanitize = "ASAN"\nextra_cflags = [ "-fsanitize=fuzzer-no-link,address" ]\nextra_ldflags = [ "-fuse-ld=lld", "-Wl,-rpath,/root/clang/lib", "-fsanitize=fuzzer-no-link,address" ]\nis_official_build=false\nis_component_build = false\nskia_enable_gpu = true\nskia_build_fuzzers=true' > out/full/args.gn && \
    bin/gn gen out/full && \
    ninja -C out/full

# Build Skia fuzzers with ASAN and coverage instrumentation.
RUN mkdir -p out/cov_full && \
    echo 'cc = "/root/clang/bin/clang"\ncxx = "/root/clang/bin/clang++"\nsanitize = "ASAN"\nextra_cflags = [ "-fsanitize=fuzzer-no-link,address","-fprofile-arcs","-ftest-coverage","-fno-inline" ]\nextra_ldflags = [ "-fuse-ld=lld", "-Wl,-rpath,/root/clang/lib", "-fsanitize=fuzzer-no-link,address","--coverage" ]\nis_official_build=false\nis_component_build = false\nskia_enable_gpu = true\nskia_build_fuzzers=true' > out/cov_full/args.gn && \
    bin/gn gen out/cov_full && \
    ninja -C out/cov_full

RUN apt-get install -y npm && npm install -g lcov-parse

# Copy GraphFuzz harnesses into Skia build tree.
COPY gf_fuzz /src/skia/gf_fuzz

# Copy GraphFuzz core into Skia build tree.
RUN mkdir /src/skia/graphfuzz && \
    cp -r /graphfuzz/src /src/skia/graphfuzz/src

# Patch Skia build rules.
COPY patch/BUILD.gn /src/skia/BUILD.gn

# Copy annotated Skia fuzzers into build tree.
# Note: The existing Skia fuzzers have been modified to explicitly annotate
# endpoint usage with the FUZZ_ENDPOINT macro. This was done strictly for the
# purpose of benchmarking and is not necessary for normal GraphFuzz usage.
RUN rm -rf /src/skia/fuzz
COPY patch/fuzz /src/skia/fuzz
RUN find /src/skia/fuzz -type f -exec touch {} +

# Rebuild proto
RUN cd /src/skia/graphfuzz/src && \
    LD_LIBRARY_PATH=/root/clang/lib protoc --cpp_out=. graph.proto

# Build fuzzers
RUN cd /src/skia && \
    bin/gn gen out/full/ && \
    bin/gn gen out/cov_full/ && \
    ninja -C out/full && \
    ninja -C out/cov_full

# Copy run scripts.
COPY scripts /home/scripts
WORKDIR /home/scripts

env ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
env ASAN_OPTIONS=detect_leaks=0,allocator_may_return_null=1
