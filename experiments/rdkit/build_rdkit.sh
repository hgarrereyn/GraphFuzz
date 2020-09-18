
export SRC=/src

# Build zlib
git clone --depth 1 -b master https://github.com/madler/zlib.git $SRC/zlib
cd $SRC/zlib
OLD_CFLAGS="$CFLAGS"
export LDFLAGS="-fPIC $CFLAGS"
export CFLAGS="-fPIC $CFLAGS"
# Only build static libraries, so we don't accidentally link to zlib dynamically.
./configure --static
make -j$(nproc) clean
make -j$(nproc) all install
unset LDFLAGS
export CFLAGS="$OLD_CFLAGS"

# We're building `rdkit` using clang, but the boost package is built using gcc.
# For whatever reason, linking would fail.
# (Mismatch between libstdc++ and libc++ maybe?)
# It works if we build `rdkit` using gcc or build boost using clang instead.
# We've opted for building boost using clang.
cd $SRC && \
wget --quiet https://sourceforge.net/projects/boost/files/boost/1.69.0/boost_1_69_0.tar.bz2 && \
tar xjf boost_1_69_0.tar.bz2 && \
cd $SRC/boost_1_69_0 && \
./bootstrap.sh --with-toolset=clang --with-libraries=serialization,system,iostreams,regex && \
./b2 -q -j$(nproc) toolset=clang linkflags="-fPIC $CXXFLAGS $CXXFLAGS_EXTRA" cxxflags="-fPIC $CXXFLAGS $CXXFLAGS_EXTRA" link=static install

cd $SRC/rdkit

export CC="clang"
export CXX="clang++"
export SANITIZER_FLAGS_address="-fsanitize=address -fsanitize-address-use-after-scope"
export COVERAGE_FLAGS="-fsanitize=fuzzer-no-link"
export CFLAGS="-g -O1 -fno-omit-frame-pointer -gline-tables-only -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION $COVERAGE_FLAGS $SANITIZER_FLAGS_address"
export CXXFLAGS="$CFLAGS"

mkdir -p build && cd build

cmake .. \
    -DRDK_BUILD_PYTHON_WRAPPERS=OFF \
    -DRDK_BUILD_FREETYPE_SUPPORT=OFF \
    -DRDK_BUILD_FUZZ_TARGETS=OFF \
    -DRDK_INSTALL_STATIC_LIBS=ON \
    -DBoost_USE_STATIC_LIBS=ON

make -j$(nproc)
make install
