#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<int> CountKeyEqual(int A[], int n, int min, int max)
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

vector<int> CountKeyLess(vector<int>& equal, int n, int min, int max)
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

void RearrangeInplace(int *A, vector<int>& less, int n, int min, int max)
{
    vector<int> next(less);

    for (int i = min; i <= max; ++i)
    {
        A[next[i]++] = i;
    }
}

vector<int> Rearrange(vector<int>& less, int n, int min, int max)
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

void CountingSortInplace(int A[], int n, int min, int max)
{
    vector<int> equal = CountKeyEqual(A, n, min, max);
    vector<int> less  = CountKeyLess(equal, n, min, max);
    RearrangeInplace(A, less, n, min, max);
}

vector<int> CountingSort(int A[], int n, int min, int max)
{
    vector<int> equal = CountKeyEqual(A, n, min, max);
    vector<int> less  = CountKeyLess(equal, n, min, max);
    return Rearrange(less, n, min, max);
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