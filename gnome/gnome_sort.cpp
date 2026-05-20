#include "sorts.h"
#include <utility>

namespace sorts {

    void gnome_sort(std::vector<int>& vec) {
        int index = 0;
        int n = vec.size();

        while (index < n) {
            if (index == 0 || vec[index] >= vec[index - 1]) {
                index++;
            }
            else {
                std::swap(vec[index], vec[index - 1]);
                index--;
            }
        }
    }
}