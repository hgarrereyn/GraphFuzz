#!/usr/bin/env bash

set -e

echo "[+] building core"
rm -rf build
mkdir build
pushd build
export CC=clang
export CXX=clang++
export CFLAGS="-flto=full -ggdb"
export CXXFLAGS="-flto=full -ggdb"
cmake -G Ninja ..
ninja
sudo ninja install
popd

echo "[+] building core with asan"
rm -rf build.asan
mkdir build.asan
pushd build.asan
export CC=clang
export CXX=clang++
export CFLAGS="-flto=full -ggdb -fsanitize=address,undefined"
export CXXFLAGS="-flto=full -ggdb -fsanitize=address,undefined"
cmake -G Ninja ..
ninja
popd

echo "[+] building python tool"
pushd cli
poetry build
poetry export > dist/requirements.txt
pip install --user -r dist/requirements.txt
pip install --user -e .
