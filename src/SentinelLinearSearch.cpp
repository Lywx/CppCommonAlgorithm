#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
int SentinelLinearSearch(T A[], int n, T x)
{
    T ALast = A[n - 1];
    int i = 0;
    while(A[i] != x)
    {
        ++i;
    }

    A[n - 1] = ALast;

    bool foundPrev = i < n - 1;
    bool foundLast = ALast == x;
    return foundLast || foundPrev ? i : NOT_FOUND;
}

// A: an array.
// n: the number of elements in A to search through.
// x: the value being searched for.
int SentinelLinearSearch(int A[], int n, int x)
{
    // Set up sentinel
    auto ALast = A[n - 1];
    A[n - 1] = x;

    auto i = 0;
    while(A[i] != x)
    {
        ++i;
    }

    // Restore sentinel
    A[n - 1] = ALast;

    bool foundPrevious = i < n - 1;
    bool foundLast = ALast == x;

    return foundPrevious || foundLast ? i : NOT_FOUND;
}
