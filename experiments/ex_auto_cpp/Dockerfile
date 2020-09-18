FROM graphfuzz_base

COPY in /harness/in

RUN cd /harness/in && \
    ./build_lib.sh && \
    ./build.sh

WORKDIR /harness/in
ENV ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
