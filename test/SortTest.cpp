#include "catch.hpp"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#include <InsertionSort.cpp>
#include <SelectionSort.cpp>
#include <MergeSort.cpp>
#include <QuickSort.cpp>
#include <CountingSort.cpp>
#include <HeapSort.cpp>
#include <BubbleSort.cpp>

using namespace std;

const int SortCount = 9;
void SortResult(int *A, int n, int index)
{
    switch (index)
    {
    case 0:
        InsertionSort(A, n);
        break;

    case 1:
        SelectionSort(A, n);
        break;

    case 2:
        MergeSort(A, 0, n - 1, INT_MAX);
        break;

    case 3:
        MergeSortUsingVector(A, 0, n - 1, INT_MAX);
        break;

    case 4:
        QuickSort(A, 0, n - 1);
        break;

    case 5:
        CountingSortInplace(A, n, 0, n - 1);
        break;

    case 6:
    {
        auto result = CountingSort(A, n, 0, n - 1);
        copy(result.begin(), result.end(), A);
    }
    break;

    case 7:
        HeapSort(A, n);
        break;

    case 8:
        BubbleSort(A, n);
        break;

    default:
        break;
    }
}

void RequireResult(int *A, int *AExpect, int n, int line)
{
    int *B = new int[n];

    for (int index = 0; index < SortCount; ++index)
    {
        memcpy(B, A, sizeof(int) * n);
        SortResult(B, n, index);

        INFO("Line number: " + to_string(line));
        INFO("Method index: " + to_string(index));

        for (auto i = 0; i < n; ++i)
        {
            REQUIRE(B[i] == AExpect[i]);
        }
    }

    delete[] B;
}

#define REQUIRE_RESULT(A, AExpect, n) RequireResult(A, AExpect, n, __LINE__);

TEST_CASE("Sort Test", "")
{
    SECTION("")
    {
        int A[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
        int AExpect[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        int n = 10;

        REQUIRE_RESULT(A, AExpect, n);
    }
}
