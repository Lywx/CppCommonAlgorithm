#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
void MergeUsingNewArray(T A[], int begin, int end, int middle, T sentinel)
{
    int n1 = middle - begin + 1;
    int n2 = end - middle;

    // The order of execution should be identical to figure in P43
    // printf("%d %d %d\n", begin + 1, middle + 1, end + 1);

    // The extra element is for sentinel
    T *B = new T[n1 + 1];
    T *C = new T[n2 + 1];

    for (int i = begin, j = 0; i <= middle; ++i, ++j)
    {
        B[j] = A[i];
    }
    B[n1] = sentinel;

    for (int i = middle + 1, j = 0; i <= end; ++i, ++j)
    {
        C[j] = A[i];
    }
    C[n2] = sentinel;

    int bIndex = 0, cIndex = 0;
    for (int aIndex = begin; aIndex <= end; ++aIndex)
    {
        if (B[bIndex] <= C[cIndex])
        {
            A[aIndex] = B[bIndex];
            ++bIndex;
        }
        else
        {
            A[aIndex] = C[cIndex];
            ++cIndex;
        }
    }

    delete[] B;
    delete[] C;
}

template <typename T>
void MergeUsingNewVector(T A[], int begin, int end, int middle, T sentinel) noexcept
{
    int n1 = middle - begin + 1;
    int n2 = end - middle;

    // The order of execution should be identical to figure in P43
    // printf("%d %d %d\n", begin + 1, middle + 1, end + 1);

    // The extra element is for sentinel
    vector<T> B = vector<T>(n1 + 1, sentinel);
    vector<T> C = vector<T>(n2 + 1, sentinel);

    // Or use:
    // for (int i = begin, j = 0; j < n1; ++i, ++j)
    for (int i = begin, j = 0; i <= middle; ++i, ++j)
    {
        B[j] = A[i];
    }

    // Or use:
    // for (int i = middle + 1, j = 0; j < n2; ++i, ++j)
    for (int i = middle + 1, j = 0; i <= end; ++i, ++j)
    {
        C[j] = A[i];
    }

    int bIndex = 0, cIndex = 0;
    for (int aIndex = begin; aIndex <= end; ++aIndex)
    {
        if (B[bIndex] <= C[cIndex])
        {
            A[aIndex] = B[bIndex];
            ++bIndex;
        }
        else
        {
            A[aIndex] = C[cIndex];
            ++cIndex;
        }
    }
}

inline void MergeUsingPreallocatedArray(int A[], int begin, int end, int middle, int sentinel)
{
    static int MergeArrayB[1000];
    static int MergeArrayC[1000];

    int n1 = middle - begin + 1;
    int n2 = end - middle;

    // The order of execution should be identical to figure in P43
    // printf("%d %d %d\n", begin + 1, middle + 1, end + 1);

    // NOTE(Wuxiang): Use preallocated memory to reduce memory bottleneck.
    int *B = MergeArrayB;
    int *C = MergeArrayC;

    for (int i = begin, j = 0; i <= middle; ++i, ++j)
    {
        B[j] = A[i];
    }
    B[n1] = sentinel;

    for (int i = middle + 1, j = 0; i <= end; ++i, ++j)
    {
        C[j] = A[i];
    }
    C[n2] = sentinel;

    int bIndex = 0, cIndex = 0;
    for (int aIndex = begin; aIndex <= end; ++aIndex)
    {
        if (B[bIndex] <= C[cIndex])
        {
            A[aIndex] = B[bIndex];
            ++bIndex;
        }
        else
        {
            A[aIndex] = C[cIndex];
            ++cIndex;
        }
    }
}

template <typename T>
void MergeSortUsingNewArray(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MergeSortUsingNewArray(A, begin, middle, sentinel);
    MergeSortUsingNewArray(A, middle + 1, end, sentinel);
    MergeUsingNewArray(A, begin, end, middle, sentinel);
}

template <typename T>
void MergeSortUsingNewVector(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MergeSortUsingNewVector(A, begin, middle, sentinel);
    MergeSortUsingNewVector(A, middle + 1, end, sentinel);
    MergeUsingNewVector(A, begin, end, middle, sentinel);
}

inline void MergeSortUsingPreallocatedArray(int A[], int begin, int end, int sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MergeSortUsingPreallocatedArray(A, begin, middle, sentinel);
    MergeSortUsingPreallocatedArray(A, middle + 1, end, sentinel);
    MergeUsingPreallocatedArray(A, begin, end, middle, sentinel);
}
