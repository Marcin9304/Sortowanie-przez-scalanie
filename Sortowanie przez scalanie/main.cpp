#include <iostream>
#include <vector>
#include "MergeSorter.h"

// Funkcja pomocnicza do wyœwietlania wektora
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Demonstracja MergeSort ===\n" << std::endl;

    // 1. Instancja dla liczb ca³kowitych (int)
    MergeSorter<int> intSorter;
    std::vector<int> intVec = { 12, 7, 14, 9, 10, 11 };

    std::cout << "Tablica int przed sortowaniem: ";
    printVector(intVec);

    intSorter.sort(intVec);

    std::cout << "Tablica int po sortowaniu:     ";
    printVector(intVec);
    std::cout << "-----------------------------" << std::endl;

    // 2. Instancja dla liczb zmiennoprzecinkowych (double)
    MergeSorter<double> doubleSorter;
    std::vector<double> doubleVec = { 3.14, 1.59, 2.65, 3.58, 9.79 };

    std::cout << "Tablica double przed sortowaniem: ";
    printVector(doubleVec);

    doubleSorter.sort(doubleVec);

    std::cout << "Tablica double po sortowaniu:     ";
    printVector(doubleVec);

    return 0;
}