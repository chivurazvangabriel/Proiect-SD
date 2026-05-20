#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Constants for dataset sizes
const int SIZE_SMALL = 20000;
const int SIZE_BIG   = 10000000;

// Helper function to write a vector to a file efficiently
void write_to_file(const string& filepath, const vector<int>& vec) {
    ofstream out(filepath);
    if (!out) {
        cerr << "Error opening file: " << filepath << " (Check your working directory)" << endl;
        return;
    }

    // Write total element count as the first line
    out << vec.size() << "\n";

    // Write elements separated by spaces
    for (size_t i = 0; i < vec.size(); ++i) {
        out << vec[i] << (i + 1 == vec.size() ? "" : " ");
    }
    out << "\n";
}

// Generates the theoretical worst case for Merge Sort by interleaving elements
void generate_merge_worst(vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    vector<int> left_sub, right_sub;
    for (int i = left; i <= right; i++) {
        if ((i - left) % 2 == 0) left_sub.push_back(vec[i]);
        else right_sub.push_back(vec[i]);
    }

    int idx = left;
    for (int val : left_sub)  vec[idx++] = val;
    for (int val : right_sub) vec[idx++] = val;

    generate_merge_worst(vec, left, mid);
    generate_merge_worst(vec, mid + 1, right);
}

void create_merge_sort_cases() {
    // 1. Best Case
    vector<int> small_best(SIZE_SMALL);
    iota(small_best.begin(), small_best.end(), 1);
    write_to_file("../merge/small_merge_sort_best.in", small_best);

    vector<int> big_best(SIZE_BIG);
    iota(big_best.begin(), big_best.end(), 1);
    write_to_file("../merge/big_merge_sort_best.in", big_best);

    // 2. Worst Case
    vector<int> small_worst(SIZE_SMALL);
    iota(small_worst.begin(), small_worst.end(), 1);
    generate_merge_worst(small_worst, 0, SIZE_SMALL - 1);
    write_to_file("../merge/small_merge_sort_worst.in", small_worst);

    vector<int> big_worst(SIZE_BIG);
    iota(big_worst.begin(), big_worst.end(), 1);
    generate_merge_worst(big_worst, 0, SIZE_BIG - 1);
    write_to_file("../merge/big_merge_sort_worst.in", big_worst);
}

void create_radix_sort_cases() {
    // 1. Best Case
    vector<int> small_best(SIZE_SMALL);
    for (int i = 0; i < SIZE_SMALL; ++i) small_best[i] = i % 10;
    write_to_file("../radix/small_radix_sort_best.in", small_best);

    vector<int> big_best(SIZE_BIG);
    for (int i = 0; i < SIZE_BIG; ++i) big_best[i] = i % 10;
    write_to_file("../radix/big_radix_sort_best.in", big_best);

    // 2. Worst Case
    vector<int> small_worst(SIZE_SMALL, 5);
    small_worst.back() = 2000000000;
    write_to_file("../radix/small_radix_sort_worst.in", small_worst);

    vector<int> big_worst(SIZE_BIG, 5);
    big_worst.back() = 2000000000;
    write_to_file("../radix/big_radix_sort_worst.in", big_worst);
}

void create_gnome_sort_cases() {
    // 1. Best Case
    vector<int> small_best(SIZE_SMALL);
    iota(small_best.begin(), small_best.end(), 1);
    write_to_file("../gnome/small_gnome_sort_best.in", small_best);

    vector<int> big_best(SIZE_BIG);
    iota(big_best.begin(), big_best.end(), 1);
    write_to_file("../gnome/big_gnome_sort_best.in", big_best);

    // 2. Worst Case
    vector<int> small_worst(SIZE_SMALL);
    iota(small_worst.begin(), small_worst.end(), 1);
    reverse(small_worst.begin(), small_worst.end());
    write_to_file("../gnome/small_gnome_sort_worst.in", small_worst);

    vector<int> big_worst(SIZE_BIG);
    iota(big_worst.begin(), big_worst.end(), 1);
    reverse(big_worst.begin(), big_worst.end());
    write_to_file("../gnome/big_gnome_sort_worst.in", big_worst);
}

int maine() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Generating test files inside manual directories..." << endl;

    create_merge_sort_cases();
    cout << "-> Target [merge/] completed." << endl;

    create_radix_sort_cases();
    cout << "-> Target [radix/] completed." << endl;

    create_gnome_sort_cases();
    cout << "-> Target [gnome/] completed." << endl;

    cout << "\nAll data generated successfully!" << endl;
    return 0;
}