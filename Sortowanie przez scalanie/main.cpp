/**
 * @file main.cpp
 * @brief G³ówny plik programu demonstruj¹cy dzia³anie algorytmu MergeSort.
 * @author Twoje Imie i Nazwisko
 * @date 2023-11-26
 *
 * Plik zawiera funkcjê g³ówn¹, która tworzy instancje szablonu klasy MergeSorter
 * dla typów int oraz double, a nastêpnie prezentuje wyniki sortowania na standardowym wyjœciu.
 */

#include <iostream>
#include <vector>
#include "MergeSorter.h"

 /**
  * @brief Funkcja pomocnicza do wyœwietlania zawartoœci wektora w konsoli.
  * * Funkcja przechodzi przez wszystkie elementy wektora i wypisuje je
  * oddzielone spacj¹.
  * * @tparam T Typ danych przechowywanych w wektorze.
  * @param vec Referencja do sta³ego wektora, który ma zostaæ wyœwietlony.
  */
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief G³ówna funkcja wejœciowa programu.
 * * W tej funkcji realizowane s¹ nastêpuj¹ce kroki:
 * 1. Utworzenie instancji MergeSorter dla liczb ca³kowitych (int).
 * 2. Posortowanie i wyœwietlenie przyk³adowej tablicy int.
 * 3. Utworzenie instancji MergeSorter dla liczb zmiennoprzecinkowych (double).
 * 4. Posortowanie i wyœwietlenie przyk³adowej tablicy double.
 * * @return Zwraca 0, informuj¹c system operacyjny o poprawnym zakoñczeniu programu.
 */
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