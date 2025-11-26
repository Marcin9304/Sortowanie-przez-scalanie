#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSorter.h" 
#include <vector>
#include <algorithm> // do std::is_sorted
#include <random>    // do generowania losowych liczb

// Klasa testowa (Fixture) - opcjonalna, ale porzadkuje kod
template <typename T>
class MergeSorterTest : public ::testing::Test {
protected:
    MergeSorter<T> sorter;
};

// 1. Zachowuje tablice niezmieniona, gdy jest juz posortowana rosnaco
TEST(MergeSortTest, AlreadySorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 2. Potrafi posortowac tablice posortowana w odwrotnej kolejnosci
TEST(MergeSortTest, ReverseSorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 3. Poprawnie sortuje losowa tablice liczb
TEST(MergeSortTest, RandomArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 42, 15, 8, 23, 4, 16 };
    sorter.sort(vec);
    // Sprawdzamy za pomoca funkcji z biblioteki standardowej
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, AllNegative) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -5, -1, -10, -3 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i dodatnimi
TEST(MergeSortTest, MixedNegativeAndPositive) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -5, 10, 0, -2, 5 };
    std::vector<int> expected = { -5, -2, 0, 5, 10 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 6. Obs³uguje pusta tablice bez rzucania wyjatkiem
TEST(MergeSortTest, EmptyArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec = {};
    EXPECT_NO_THROW(sorter.sort(vec));
    EXPECT_TRUE(vec.empty());
}

// 7. Nie zmienia tablicy, ktora zawiera tylko jeden element
TEST(MergeSortTest, SingleElement) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 8. Poprawnie sortuje tablice z duplikatami liczb
TEST(MergeSortTest, Duplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 5, 1, 5, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 5, 5 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 9. Poprawnie sortuje tablice ujemna z duplikatami
TEST(MergeSortTest, NegativeDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -5, -1, -5, -2, -1 };
    std::vector<int> expected = { -5, -5, -2, -1, -1 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -2, 2, 0, -2, 2 };
    std::vector<int> expected = { -2, -2, 0, 2, 2 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 11. Poprawnie sortuje tablice zawieraj¹ca tylko dwa elementy w kolejnosci rosnacej
TEST(MergeSortTest, TwoElementsSorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 1, 10 };
    std::vector<int> expected = { 1, 10 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}

// 12. Poprawnie sortuje duza tablice zawieraj¹ca ponad 100 elementow
TEST(MergeSortTest, LargeArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec(150);
    // Generowanie liczb 150, 149, ..., 1
    int val = 150;
    for (auto& x : vec) x = val--;

    sorter.sort(vec);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    EXPECT_EQ(vec.size(), 150);
}

// 13. Poprawnie sortuje duza tablice (100+) z ujemnymi, dodatnimi i duplikatami
TEST(MergeSortTest, LargeComplexArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec;
    // Generujemy losowe dane
    std::mt19937 rng(42); // stale ziarno dla powtarzalnosci
    std::uniform_int_distribution<int> dist(-50, 50);

    for (int i = 0; i < 150; ++i) {
        vec.push_back(dist(rng));
    }

    sorter.sort(vec);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    EXPECT_EQ(vec.size(), 150);
}

// Testy dla typu double (dodatkowo, aby sprawdzic dzialanie szablonu)
TEST(MergeSortTest, DoubleType) {
    MergeSorter<double> sorter;
    std::vector<double> vec = { 3.5, -1.1, 3.5, 0.0 };
    std::vector<double> expected = { -1.1, 0.0, 3.5, 3.5 };
    sorter.sort(vec);
    EXPECT_EQ(vec, expected);
}