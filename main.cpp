#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <chrono>
#include <ranges>
#include "sorts.h"

using namespace std;

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
    
    sorts::merge_sort(a);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Time taken: " << elapsed.count() << " seconds\n";

    assert(is_sorted(a.begin(), a.end()));
    return 0;
}