#pragma once

#include <vector>
#include <algorithm>

using namespace std;

namespace sorts {
    void heap_sort(vector<int>& vec);
    void quick_sort(vector<int>& vec);
    void merge_sort(vector<int>& vec);
    void intro_sort(vector<int>& vec);
    void patience_sorting(vector<int>& vec);
    void radix_sort(vector<int>& vec);
    void bubble_sort(vector<int>& vec);
    void insertion_sort(vector<int>& vec);
    void gnome_sort(vector<int>& vec);
}
