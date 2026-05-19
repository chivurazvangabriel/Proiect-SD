#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void generateFile(std::string filename, int n, std::string type) {
    std::ofstream fout(filename);
    fout << n << "\n";
    
    std::vector<int> a(n);
    if (type == "best") { // Sortat crescător
        for (int i = 0; i < n; ++i) fout << i << " ";
    } else if (type == "worst") { // Sortat invers
        for (int i = 0; i < n; ++i) fout << n - i << " ";
    } else if (type == "random") { // Aleatoriu
        for (int i = 0; i < n; ++i) fout << rand() % 1000000 << " ";
    } else if (type == "few_unique") { // Multe duplicate
        for (int i = 0; i < n; ++i) fout << rand() % 10 << " ";
    } else if (type == "almost") { // Aproape sortat
        for (int i = 0; i < n; ++i) fout << i << " ";
        fout.seekp(-10, std::ios::end); // Inversam ultimele elemente
        fout << n-1 << " " << n-2;
    }
    fout.close();
    std::cout << "Generat: " << filename << std::endl;
}

int main() {
    srand(time(0));
    // Teste mici (N=20.000)
    generateFile("small_best.in", 20000, "best");
    generateFile("small_worst.in", 20000, "worst");
    generateFile("small_random.in", 20000, "random");
    
    // Teste mari (N=10.000.000) - ATENTIE: pot ocupa mult spatiu
    generateFile("big_random.in", 10000000, "random");
    generateFile("big_worst.in", 10000000, "worst");
    
    return 0;
}