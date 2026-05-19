#include <iostream>
#include <fstream>

int main() {
    // 1. Testul "Empty" (N = 0)
    // Verifica daca programul tau crapa cand nu primeste niciun element de sortat.
    std::ofstream f1("empty_snc_01.in");
    f1 << 0 << "\n";
    f1.close();
    std::cout << "Generat: empty_snc_01.in" << std::endl;

    // 2. Testul "Single Element" (N = 1)
    // Verifica daca algoritmul intra in bucle infinite cand are doar 1 element.
    std::ofstream f2("one_elem_snc_02.in");
    f2 << 1 << "\n";
    f2 << 42 << "\n"; 
    f2.close();
    std::cout << "Generat: one_elem_snc_02.in" << std::endl;

    // 3. Testul "All Equal - Big" (N = 10.000.000)
    // Este "ucigasul" pentru implementarile slabe de Quick Sort.
    std::ofstream f3("all_equal_big_snc_01.in");
    int n_big = 10000000;
    f3 << n_big << "\n";
    for (int i = 0; i < n_big; ++i) {
        f3 << 7 << " "; // Toate elementele vor fi numarul 7
    }
    f3.close();
    std::cout << "Generat: all_equal_big_snc_01.in" << std::endl;

    std::cout << "Toate cele 3 teste speciale au fost generate cu succes!" << std::endl;
    
    return 0;
}