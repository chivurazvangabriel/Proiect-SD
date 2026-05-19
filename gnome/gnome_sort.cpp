#include "../sorts.h"
#include <utility> // For std::swap

namespace sorts {

    // Public function assigned to your teammate
    void gnome_sort(std::vector<int>& vec) {
        int index = 0;
        int n = vec.size();

        while (index < n) {
            // If we are at the beginning, or the current element is greater 
            // than or equal to the previous one, step forward!
            if (index == 0 || vec[index] >= vec[index - 1]) {
                index++;
            } 
            // If they are out of order, swap them and step backward!
            else {
                std::swap(vec[index], vec[index - 1]);
                index--;
            }
        }
    }
}