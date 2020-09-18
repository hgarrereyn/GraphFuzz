FROM graphfuzz_base

RUN apt-get -y update && apt-get -y install clang++-10

RUN git clone https://github.com/Softmotions/iowow.git
WORKDIR iowow
RUN mkdir build && \
    cd build && \
    CC=clang-10 CFLAGS="-fsanitize=fuzzer-no-link,address" cmake .. -DCMAKE_BUILD_TYPE=Debug && \
    make -j8 && \
    make install

COPY in /harness/in
WORKDIR /harness/in

env LD_LIBRARY_PATH=/usr/local/lib
env ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer
env ASAN_OPTIONS=detect_leaks=0
CMD /bin/zsh
