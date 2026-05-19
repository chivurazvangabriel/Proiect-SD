#include "sorts.h"

namespace sorts {

    // A helper function to get the maximum value in the vector
    // This tells us how many total digits we need to process
    int get_max(const std::vector<int>& vec) {
        int max_val = vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            if (vec[i] > max_val) {
                max_val = vec[i];
            }
        }
        return max_val;
    }

    // A stable counting sort helper that sorts vec based on the digit 
    // represented by 'exp' (e.g., exp = 1 for ones, 10 for tens, 100 for hundreds)
    void counting_sort_for_radix(std::vector<int>& vec, int exp) {
        int n = vec.size();
        std::vector<int> output(n);
        int count[10] = {0}; // Buckets for digits 0-9

        // Store occurrences of digits in count[]
        for (int i = 0; i < n; ++i) {
            int digit = (vec[i] / exp) % 10;
            count[digit]++;
        }

        // Change count[i] so that it contains the actual position of
        // this digit in the output array
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        // Build the output array. We loop backward to maintain stability!
        for (int i = n - 1; i >= 0; --i) {
            int digit = (vec[i] / exp) % 10;
            output[count[digit] - 1] = vec[i];
            count[digit]--;
        }

        // Copy the sorted elements back into the original vector
        for (int i = 0; i < n; ++i) {
            vec[i] = output[i];
        }
    }

    // Public function assigned to your teammate
    void radix_sort(std::vector<int>& vec) {
        if (vec.empty()) return;

        // Find the maximum number to know how many digits it has
        int max_val = get_max(vec);

        // Do counting sort for every digit. 
        // exp is 10^i where i is the current digit position (1, 10, 100, ...)
        for (int exp = 1; max_val / exp > 0; exp *= 10) {
            counting_sort_for_radix(vec, exp);
        }
    }
}