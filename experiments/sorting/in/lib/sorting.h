#ifndef SORTING_H
#define SORTING_H
#include <vector>

class Sort {
public:
    Sort() {}
    int* bubbleSortWrapper(int* arr, int n);
    int* mergeSortWrapper(int* arr, int n);
    int* qSortWrapper(int* arr, int n);
};

#endif