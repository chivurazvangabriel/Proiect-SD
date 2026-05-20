#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <chrono>
#include <ranges>
#include <fstream>
#include "sorts.h"

using namespace std;

ifstream fin("../radix/big_radix_sort_worst.in");


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    fin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        fin >> x;
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    
    sorts::radix_sort(a);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Time taken: " << elapsed.count() << " seconds\n";

    assert(is_sorted(a.begin(), a.end()));
    return 0;
}