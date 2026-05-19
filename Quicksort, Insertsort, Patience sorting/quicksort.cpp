#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <random> 

void quickSort3Way(std::vector<int>& a, int left, int right) {
    if (left >= right) return;
    
    static std::mt19937 mt(1337); 
    
    std::uniform_int_distribution<int> dist(left, right);
    int pivotIndex = dist(mt); 
    
    int pivot = a[pivotIndex];
    
    int i = left, lt = left, gt = right;
    while (i <= gt) {
        if (a[i] < pivot) {
            std::swap(a[i], a[lt]);
            i++;
            lt++;
        } else if (a[i] > pivot) {
            std::swap(a[i], a[gt]);
            gt--;
        } else {
            i++;
        }
    }
    
    quickSort3Way(a, left, lt - 1);
    quickSort3Way(a, gt + 1, right);
}

void quickSort(std::vector<int>& a) {
    if (!a.empty()) {
        quickSort3Way(a, 0, (int)a.size() - 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    
    quickSort(a);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Timp Quick Sort: " << elapsed.count() << " secunde\n";
    
    assert(std::is_sorted(a.begin(), a.end())); 
    
    return 0;
}