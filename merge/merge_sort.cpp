//
// Created by minec on 5/19/2026.
//

#include "../sorts.h"

// Forward declaration of the helper functions
void merge(vector<int>& vec, vector<int>& temp, int left, int mid, int right);
void merge_sort_internal(vector<int>& vec, vector<int>& temp, int left, int right);

// The main public function from your header
void sorts::merge_sort(vector<int>& vec) {
    if (vec.size() <= 1) return;

    // Allocate the temp buffer once to optimize space overhead
    vector<int> temp(vec.size());
    merge_sort_internal(vec, temp, 0, vec.size() - 1);
}

// The recursive divide-and-conquer function
void merge_sort_internal(vector<int>& vec, vector<int>& temp, int left, int right) {
    if (left >= right) return;

    // Calculate mid-point without risking overflow (good practice for large arrays)
    int mid = left + (right - left) / 2;

    // Recursively sort the left and right halves
    merge_sort_internal(vec, temp, left, mid);
    merge_sort_internal(vec, temp, mid + 1, right);

    // Merge the sorted halves back together
    merge(vec, temp, left, mid, right);
}

// The actual conquer step
void merge(vector<int>& vec, vector<int>& temp, int left, int mid, int right) {
    int i = left;      // Starting index for the left subarray
    int j = mid + 1;   // Starting index for the right subarray
    int k = left;      // Starting index for the temporary buffer

    // Compare elements from both halves and place the smaller one into temp
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    // Copy over any remaining elements from the left subarray (if any)
    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    // Copy over any remaining elements from the right subarray (if any)
    while (j <= right) {
        temp[k++] = vec[j++];
    }

    // Copy the sorted elements from temp back into the original vector
    for (int index = left; index <= right; ++index) {
        vec[index] = temp[index];
    }
}

