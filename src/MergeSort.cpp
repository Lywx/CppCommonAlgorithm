#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
void MERGE(T A[], int begin, int end, int middle, T sentinel)
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
void MERGE_SORT(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MERGE_SORT(A, begin, middle, sentinel);
    MERGE_SORT(A, middle + 1, end, sentinel);
    MERGE(A, begin, end, middle, sentinel);
}

template <typename T>
void MERGE_USING_VECTOR(T A[], int begin, int end, int middle, T sentinel) noexcept
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

void MERGE_USING_VECTOR(int A[], int begin, int end, int middle, int sentinel) noexcept
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
void MERGE_SORT_USING_VECTOR(T A[], int begin, int end, T sentinel)
{
    if (begin >= end)
    {
        return;
    }

    int middle = (begin + end) / 2;

    MERGE_SORT_USING_VECTOR(A, begin, middle, sentinel);
    MERGE_SORT_USING_VECTOR(A, middle + 1, end, sentinel);
    MERGE_USING_VECTOR(A, begin, end, middle, sentinel);
}

int main(int argc, char **argv)
{
    int A[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
    int S[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int n = 10;

    MERGE_SORT(A, 0, n - 1, INT_MAX);
    // MERGE_SORT_USING_VECTOR(A, 0, n - 1, INT_MAX);

    for (auto i = 0; i < n; ++i)
    {
        assert(A[i] == S[i]);
    }

    return 0;
}
