FROM graphfuzz_base

COPY in /harness/in
WORKDIR /harness/in

RUN ./build_lib.sh && ./build.sh

ENV ASAN_OPTIONS=detect_leaks=0
ENV ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
CMD /bin/zsh
