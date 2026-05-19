#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

// ==========================================
// INSERTION SORT IMPLEMENTATION
// ==========================================
void insertionSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// ==========================================
// REQUIRED TEMPLATE (With local timing)
// ==========================================
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    
    // Calling the specific sort directly
    insertionSort(a);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Time taken: " << elapsed.count() << " seconds\n";
    
    assert(std::ranges::is_sorted(a));
    return 0;
}