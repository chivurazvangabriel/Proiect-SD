#include <vector>
#include <cmath>
#include <algorithm>

namespace sorts {
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify(std::vector<int>& arr, int n, int i, int offset) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[offset + left] > arr[offset + largest]) {
        largest = left;
    }

    if (right < n && arr[offset + right] > arr[offset + largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[offset + i], arr[offset + largest]);
        heapify(arr, n, largest, offset);
    }
}

void heapSort(std::vector<int>& arr, int left, int right) {
    int n = right - left + 1;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, left);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[left], arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void introSortUtil(std::vector<int>& arr, int begin, int end, int depthLimit) {
    int size = end - begin + 1;

    if (size < 16) {
        insertionSort(arr, begin, end);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, begin, end);
        return;
    }

    int pivot = partition(arr, begin, end);
    introSortUtil(arr, begin, pivot - 1, depthLimit - 1);
    introSortUtil(arr, pivot + 1, end, depthLimit - 1);
}

void intro_sort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int depthLimit = 2 * std::log2(arr.size());
    introSortUtil(arr, 0, arr.size() - 1, depthLimit);
}
}