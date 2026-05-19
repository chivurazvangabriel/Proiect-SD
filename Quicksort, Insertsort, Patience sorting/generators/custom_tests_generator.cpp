#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

// 1. Functie pentru testul cu "numere egale in cantitate descrescatoare"
void generateDecreasingFrequency(std::string filename, int n) {
    std::ofstream fout(filename);
    fout << n << "\n";
    
    int remaining = n;
    // Setam o cantitate initiala mare. 
    // Matematica ne spune ca suma numerelor de la 1 la k este k*(k+1)/2.
    // Pentru n = 20.000, sqrt(40.000) e aproximativ 200.
    int current_quantity = (int)std::sqrt(2 * n) + 50; 
    int val = 1;
    
    while (remaining > 0) {
        int to_write = std::min(remaining, current_quantity);
        for (int i = 0; i < to_write; ++i) {
            fout << val << " ";
        }
        remaining -= to_write;
        
        // Scadem cantitatea pentru urmatorul numar
        current_quantity = std::max(1, current_quantity - 1); 
        val++;
    }
    fout.close();
    std::cout << "Generat test freq: " << filename << std::endl;
}

// 2 & 3. Functie pentru blocuri sortate, dar interschimbate
void generateShuffledBlocks(std::string filename, int n, int num_blocks) {
    std::ofstream fout(filename);
    fout << n << "\n";
    
    int block_size = n / num_blocks;
    std::vector<std::vector<int>> blocks(num_blocks);
    
    // Generam blocurile continuu crescatoare
    int current_val = 1;
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < block_size; ++j) {
            blocks[i].push_back(current_val++);
        }
    }
    
    // Amestecam ordinea blocurilor
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(blocks.begin(), blocks.end(), g);
    
    // Scriem in fisier
    for (const auto& block : blocks) {
        for (int x : block) {
            fout << x << " ";
        }
    }
    
    // Daca raman elemente pe dinafara (din cauza impartirii), le adaugam la final
    int remaining = n % num_blocks;
    for (int i = 0; i < remaining; ++i) {
        fout << current_val++ << " ";
    }
    
    fout.close();
    std::cout << "Generat test blocks: " << filename << std::endl;
}

int main() {
    // 1. Numar egal in cantitate descrescatoare (Small)
    generateDecreasingFrequency("freq_small_snc_01.in", 20000);
    
    // 2. Blocuri sortate dar amestecate (Small - N = 20.000, impartit in 20 de blocuri a cate 1.000 elemente)
    generateShuffledBlocks("blocks_small_snc_01.in", 20000, 20);
    
    // 3. Blocuri sortate dar amestecate (Big - N = 10.000.000, impartit in 500 de blocuri)
    // ATENTIE: Acest test va dura cateva secunde bune pentru a fi scris pe disc si va avea ~80MB.
    generateShuffledBlocks("blocks_big_snc_01.in", 10000000, 500);
    
    std::cout << "Toate testele customizate au fost generate cu succes!" << std::endl;
    return 0;
}