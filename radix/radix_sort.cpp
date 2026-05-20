#include "sorts.h"

int get_max(const std::vector<int>& vec) {
    int max_val = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    return max_val;
}

void counting_sort_for_radix(std::vector<int>& vec, int exp) {
    int n = vec.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i) {
        int digit = (vec[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = (vec[i] / exp) % 10;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i) {
        vec[i] = output[i];
    }
}

void sorts::radix_sort(std::vector<int>& vec) {
    if (vec.empty()) return;

    int max_val = get_max(vec);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_for_radix(vec, exp);
    }
}