
cd lib
clang++ -c sorting.cpp
ar rcs libsorting.a sorting.o
# llvm-ar-6.0 rc libsorting.a sorting.o