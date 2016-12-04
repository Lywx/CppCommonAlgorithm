#include "catch.hpp"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#include <InsertionSort.hpp>
#include <SelectionSort.hpp>
#include <MergeSort.hpp>
#include <QuickSort.hpp>
#include <CountingSort.hpp>
#include <HeapSort.hpp>
#include <BubbleSort.hpp>
#include <ShellSort.hpp>

#include "PerformanceCounter.h"

using namespace std;

const vector<string> SortName =
{
    "Insertion Sort",
    "Selection Sort",
    "Merge Sort Using New Array",
    "Merge Sort Using New Vector",
    "Merge Sort Using Preallocated Array",
    "Quick Sort",
    "Counting Sort Using Preallocated Array",
    "Counting Sort Using New Vector + Copying Once",
    "Heap Sort",
    "Bubble Sort",
    "Shell Sort A",
    "Shell Sort B",
};

const size_t SortCount = SortName.size();

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
        MergeSortUsingNewArray(A, 0, n - 1, INT_MAX);
        break;

    case 3:
        MergeSortUsingNewVector(A, 0, n - 1, INT_MAX);
        break;

    case 4:
        MergeSortUsingPreallocatedArray(A, 0, n - 1, INT_MAX);
        break;

    case 5:
        QuickSort(A, 0, n - 1);
        break;

    case 6:
        CountingSortUsingPreallocatedArray(A, n, 0, n - 1);
        break;

    case 7:
    {
        auto result = CountingSortUsingNewVector(A, n, 0, n - 1);
        copy(result.begin(), result.end(), A);
    }
    break;

    case 8:
        HeapSort(A, n);
        break;

    case 9:
        BubbleSort(A, n);
        break;

    case 10:
        ShellSortA(A, n);
        break;

    case 11:
        ShellSortB(A, n);
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
        // Test correction
        memcpy(B, A, sizeof(int) * n);
        SortResult(B, n, index);

        INFO("Line number: " + to_string(line));
        INFO("Method index: " + to_string(index));

        for (auto i = 0; i < n; ++i)
        {
            REQUIRE(B[i] == AExpect[i]);
        }

        // TODO(Wuxiang): I am a bit of confused about this result of profiling.

        // Profile performance
        PerformanceCounter counter;
        double counterBegin = counter.GetMilliseconds();

        for (int repeat = 0; repeat < 10000; ++repeat)
        {
            memcpy(B, A, sizeof(int) * n);
            SortResult(B, n, index);
        }

        double counterEnd = counter.GetMilliseconds();
        WARN("Millisecond: " + to_string(counterEnd - counterBegin) + " " + SortName[index]);
    }

    delete[] B;
}

#define REQUIRE_RESULT(A, AExpect, n) RequireResult(A, AExpect, n, __LINE__);

TEST_CASE("Sort Test", "")
{
    SECTION("Sort 1, N = 10")
    {
        int Array[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
        int ArrayExpected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int ArraySize = 10;
        REQUIRE_RESULT(Array, ArrayExpected, ArraySize);
    }

    SECTION("Sort 2, N = 20")
    {
        int Array[] = { 19, 12, 13, 9, 0, 18, 14, 1, 3, 16, 4, 10, 6, 7, 17, 8, 2, 5, 11, 15 };
        int ArrayExpected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
        int ArraySize = 20;
        REQUIRE_RESULT(Array, ArrayExpected, ArraySize);
    }

    //// Time Consuming Test
    //
    // SECTION("Sort 3, N = 1000")
    // {
    //     int Array         [1000];
    //     int ArrayExpected [1000];
    //     int ArraySize = 1000;

    //     for (int i = 0; i < 1000; ++i)
    //     {
    //         Array[i] = i;
    //         ArrayExpected[i] = i;
    //     }

    //     random_shuffle(begin(Array), end(Array));

    //     REQUIRE_RESULT(Array, ArrayExpected, ArraySize);
    //}
}

/*
    Sort Test
    Sort 1, N = 10
    -------------------------------------------------------------------------------
    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(138)
    ...............................................................................

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1.397763 Insertion Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1.444127 Selection Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 48.281412 Merge Sort Using New Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 435.194040 Merge Sort Using New Vector

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 4.674569 Merge Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 5.013912 Quick Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 2.470405 Counting Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 197.398011 Counting Sort Using New Vector + Copying Once

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 8.142807 Heap Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 5.415833 Bubble Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 2.437125 Shell Sort A

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1.956128 Shell Sort B

    -------------------------------------------------------------------------------
    Sort Test
    Sort 2, N = 20
    -------------------------------------------------------------------------------
    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(138)
    ...............................................................................

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 3.795634 Insertion Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 5.300348 Selection Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 112.392757 Merge Sort Using New Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1227.052257 Merge Sort Using New Vector

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 11.822957 Merge Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 17.604871 Quick Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 3.554425 Counting Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 252.318369 Counting Sort Using New Vector + Copying Once

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 19.312394 Heap Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 23.072188 Bubble Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 3.784541 Shell Sort A

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 4.262693 Shell Sort B

    -------------------------------------------------------------------------------
    Sort Test
    Sort 3, N = 1000
    -------------------------------------------------------------------------------
    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(138)
    ...............................................................................

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 7703.506183 Insertion Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 12198.314493 Selection Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 6854.523728 Merge Sort Using New Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 76075.597519 Merge Sort Using New Vector

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1281.007493 Merge Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 2118.441765 Quick Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 134.807877 Counting Sort Using Preallocated Array

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 6539.912755 Counting Sort Using New Vector + Copying Once

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 3091.391613 Heap Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 65956.902599 Bubble Sort

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1044.380533 Shell Sort A

    D:\Users\Works\Cpp CommonAlgorithm\test\SortTest.cpp(130):
    warning:
    Millisecond: 1002.943153 Shell Sort B

    ===============================================================================
    All tests passed (12384 assertions in 2 test cases)
*/

