#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <queue>

void patienceSort(std::vector<int>& a) {
    if (a.empty()) return;
    
    std::vector<std::vector<int>> piles;
    
    // Pasul 1: Formarea gramezilor
    for (int x : a) {
        // Cautare binara: gasim prima gramada care are top-ul >= x
        auto it = std::lower_bound(piles.begin(), piles.end(), x, 
            [](const std::vector<int>& pile, int val) {
                return pile.back() < val; // Comparam cu varful gramezii
            });
            
        if (it == piles.end()) {
            piles.push_back({x}); // Gramada noua
        } else {
            it->push_back(x); // Adaugam in gramada gasita
        }
    }
    
    // Pasul 2: Interclasarea (Merge) folosind Min-Heap
    // Pair-ul retine: {valoare, {index_gramada, index_element}}
    using Element = std::pair<int, std::pair<int, int>>;
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
    
    for (size_t i = 0; i < piles.size(); ++i) {
        // Punem cel mai mic element din fiecare gramada (aflat la finalul vectorului)
        pq.push({piles[i].back(), {(int)i, (int)piles[i].size() - 1}});
    }
    
    int idx = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        int val = top.first;
        int p = top.second.first;
        int e = top.second.second;
        
        a[idx++] = val;
        
        // Daca mai sunt elemente in gramada respectiva, il bagam pe urmatorul in coada
        if (e > 0) {
            pq.push({piles[p][e - 1], {p, e - 1}});
        }
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
    
    patienceSort(a);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Timp Patience Sort: " << elapsed.count() << " secunde\n";
    
    assert(std::is_sorted(a.begin(), a.end())); 
    
    return 0;
}