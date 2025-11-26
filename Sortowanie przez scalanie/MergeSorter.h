#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <vector>
#include <iostream>

/**
 * @brief Klasa szablonowa implementuj¹ca algorytm sortowania przez scalanie (Merge Sort).
 * * @tparam T Typ danych przechowywanych w tablicy (musi wspierac operatory porownania).
 */
template <typename T>
class MergeSorter {
public:
    /**
     * @brief Domyslny konstruktor.
     */
    MergeSorter() = default;

    /**
     * @brief Domyslny destruktor.
     */
    ~MergeSorter() = default;

    /**
     * @brief G³owna metoda sortujaca.
     * * @param arr Referencja do wektora, ktory ma zostac posortowany.
     */
    void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) return;
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    /**
     * @brief Rekurencyjna funkcja dzielaca tablicê na podproblemy.
     * * @param arr Tablica do posortowania.
     * @param left Indeks lewego konca zakresu.
     * @param right Indeks prawego konca zakresu.
     */
    void mergeSort(std::vector<T>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    /**
     * @brief Funkcja scalajaca dwie posortowane podtablice.
     * * @param arr Tablica, na ktorej operujemy.
     * @param left Poczatek lewej podtablicy.
     * @param mid Koniec lewej podtablicy.
     * @param right Koniec prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Tymczasowe wektory
        std::vector<T> L(n1);
        std::vector<T> R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

#endif // MERGESORTER_H