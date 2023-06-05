#include "sorting.h"
#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    std::vector<int> temp(high - low + 1);

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSortInPlace(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSortInPlace(arr, low, mid);
        mergeSortInPlace(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

std::vector<int> mergeSort(std::vector<int>& arr) {
    std::vector<int> res(arr);
    mergeSortInPlace(res, 0, res.size() - 1);
    return res;
}

std::vector<int> bubbleSort(std::vector<int>& arr) {
    std::vector<int> res(arr);
    int n = res.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (res[j] > res[j + 1]) {
                std::swap(res[j], res[j + 1]);
            }
        }
    }
    return res;
}



int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortInPlace(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortInPlace(arr, low, pi - 1);
        quickSortInPlace(arr, pi + 1, high);
    }
}

std::vector<int> quickSort(std::vector<int>& arr) {
    std::vector<int> res(arr);
    quickSortInPlace(res, 0, res.size() - 1);
    return res;
}

int* Sort::bubbleSortWrapper(int* arr, int n) {
    std::vector<int> in(arr, arr + n);
    std::vector<int> out;
    out = bubbleSort(in);
    int* outArr = new int[n];
    for (int i = 0; i < n; i++) {
        outArr[i] = out[i];
    }
    return outArr;
}

int* Sort::mergeSortWrapper(int* arr, int n) {
    std::vector<int> in(arr, arr + n);
    std::vector<int> out;
    out = mergeSort(in);
    int* outArr = new int[n];
    for (int i = 0; i < n; i++) {
        outArr[i] = out[i];
    }
    return outArr;
}

int* Sort::qSortWrapper(int* arr, int n) {
    std::vector<int> in(arr, arr + n);
    std::vector<int> out;
    out = quickSort(in);
    int* outArr = new int[n];
    for (int i = 0; i < n; i++) {
        outArr[i] = out[i];
    }
    return outArr;
}
