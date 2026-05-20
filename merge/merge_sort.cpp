#include "sorts.h"

void merge(vector<int>& vec, vector<int>& temp, int left, int mid, int right);
void merge_sort_internal(vector<int>& vec, vector<int>& temp, int left, int right);

void sorts::merge_sort(vector<int>& vec) {
    if (vec.size() <= 1) return;

    vector<int> temp(vec.size());
    merge_sort_internal(vec, temp, 0, vec.size() - 1);
}

void merge_sort_internal(vector<int>& vec, vector<int>& temp, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    merge_sort_internal(vec, temp, left, mid);
    merge_sort_internal(vec, temp, mid + 1, right);

    merge(vec, temp, left, mid, right);
}

void merge(vector<int>& vec, vector<int>& temp, int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= right) {
        temp[k++] = vec[j++];
    }

    for (int index = left; index <= right; ++index) {
        vec[index] = temp[index];
    }
}