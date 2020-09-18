FROM graphfuzz_base

RUN apt-get -y update && apt-get -y install clang++-10

COPY in /harness/in
WORKDIR /harness/in

env ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
env ASAN_OPTIONS=detect_leaks=0
CMD /bin/zsh
