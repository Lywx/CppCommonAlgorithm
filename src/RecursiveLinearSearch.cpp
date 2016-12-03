#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template <typename T>
int RecursiveLinearSearch(T A[], int n, int i, T x)
{
    if (i > n - 1)
    {
        return NOT_FOUND;
    }

    if (A[i] == x)
    {
        return i;
    }
    else
    {
        return RecursiveLinearSearch(A, n, i + 1, x);
    }
}

// A: an array.
// n: the number of elements in A to search through.
// x: the value being searched for.
// i: the index each iteration will look at
int RecursiveLinearSearch(int A[], int n, int i, int x)
{
    if (i > n - 1)
    {
        return NOT_FOUND;
    }

    if (A[i] == x)
    {
        return i;
    }
    else
    {
        return RecursiveLinearSearch(A, n, i + 1, x);
    }
}