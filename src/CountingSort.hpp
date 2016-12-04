#pragma once

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

inline vector<int> CountKeyEqualUsingNewVector(int A[], int n, int min, int max)
{
    int tableLength = max - min + 1;
    vector<int> equal(tableLength, 0);
    equal.reserve(tableLength);

    for (int i = 0; i < n; ++i)
    {
        ++equal[A[i]];
    }

    return equal;
}

inline void CountKeyEqualUsingPreallocatedArray(int A[], int *equal, int n, int min, int max)
{
    int tableLength = max - min + 1;
    for (int i = 0; i < tableLength; ++i)
    {
        equal[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        ++equal[A[i]];
    }
}

inline vector<int> CountKeyLessUsingNewVector(vector<int>& equal, int n, int min, int max)
{
    int tableLength = max - min + 1;
    vector<int> less(tableLength, 0);
    less.reserve(tableLength);

    for (int i = min + 1; i <= max; ++i)
    {
        less[i] = less[i - 1] + equal[i - 1];
    }

    return less;
}

inline void CountKeyLessUsingPreallocatedArray(int *equal, int *less, int n, int min, int max)
{
    int tableLength = max - min + 1;
    for (int i = 0; i < tableLength; ++i)
    {
        less[i] = 0;
    }

    for (int i = min + 1; i <= max; ++i)
    {
        less[i] = less[i - 1] + equal[i - 1];
    }
}

inline vector<int> RearrangeUsingNewVector(vector<int>& less, int n, int min, int max)
{
    vector<int> next(less);

    vector<int> B(n, 0);
    B.reserve(n);

    for (int i = min; i <= max; ++i)
    {
        B[next[i]++] = i;
    }

    return B;
}

inline void RearrangeUsingPreallocatedArray(int *A, int *less, int *next, int n, int min, int max)
{
    int tableLength = max - min + 1;
    for (int i = 0; i < tableLength; ++i)
    {
        next[i] = less[i];
    }

    for (int i = min; i <= max; ++i)
    {
        A[next[i]++] = i;
    }
}

inline void CountingSortUsingPreallocatedArray(int A[], int n, int min, int max)
{
    static int equal[1000];
    static int less[1000];
    static int next[1000];

    CountKeyEqualUsingPreallocatedArray(A, equal, n, min, max);
    CountKeyLessUsingPreallocatedArray(equal, less, n, min, max);
    RearrangeUsingPreallocatedArray(A, less, next, n, min, max);
}

inline vector<int> CountingSortUsingNewVector(int A[], int n, int min, int max)
{
    // Performance is not good because of this:
    // http://stackoverflow.com/questions/470683/memory-allocation-deallocation-bottleneck

    vector<int> equal = CountKeyEqualUsingNewVector(A, n, min, max);
    vector<int> less  = CountKeyLessUsingNewVector(equal, n, min, max);
    return RearrangeUsingNewVector(less, n, min, max);
}

// int main(int argc, char **argv)
// {
//     int A[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
//     int B[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//     int n = 10;
//
//     vector<int> C = CountingSort(A, n, 0, 9);
//
//     for (auto i = 0; i < n; ++i)
//     {
//         assert(C[i] == B[i]);
//     }
//
//     int D[] = { 99, 0, 1, 3, 4, 66, 7, 8, 2, 5 };
//     int E[] = { 0, 1, 2, 3, 4, 5, 7, 8, 66, 99 };
//
//     vector<int> F = CountingSort(D, n, 0, 99);
//
//     for (auto i = 0; i < n; ++i)
//     {
//         assert(E[i] == F[i]);
//     }
//
//     return 0;
// }