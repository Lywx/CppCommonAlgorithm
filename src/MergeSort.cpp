#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
void Merge(T A[], int begin, int end, int middle, T sentinel)
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
void MergeSort(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MergeSort(A, begin, middle, sentinel);
    MergeSort(A, middle + 1, end, sentinel);
    Merge(A, begin, end, middle, sentinel);
}

template <typename T>
void MergeUsingVector(T A[], int begin, int end, int middle, T sentinel) noexcept
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

void MergeUsingVector(int A[], int begin, int end, int middle, int sentinel) noexcept
{
    int n1 = middle - begin + 1;
    int n2 = end - middle;

    vector<int> B = vector<int>();
    B.assign(n1 + 1, sentinel);

    vector<int> C = vector<int>();
    C.assign(n2 + 1, sentinel);

    for (int i = begin, j = 0; i <= middle; ++i, ++j)
    {
        B[j] = A[i];
    }

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

template <typename T>
void MergeSortUsingVector(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MergeSortUsingVector(A, begin, middle, sentinel);
    MergeSortUsingVector(A, middle + 1, end, sentinel);
    MergeUsingVector(A, begin, end, middle, sentinel);
}
