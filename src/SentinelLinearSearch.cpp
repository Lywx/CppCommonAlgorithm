#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
int SENTINEL_LINEAR_SEARCH(T A[], int n, T x)
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
int SENTINEL_LINEAR_SEARCH(int A[], int n, int x)
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

int main(int argc, char **argv)
{
    int A[5] = { 0, 1, 2, 3, 4 };
    int n;
    int x;

    n = 5;
    x = 4;
    assert(SENTINEL_LINEAR_SEARCH(A, n, x) == 4);

    n = 5;
    x = 0;
    assert(SENTINEL_LINEAR_SEARCH(A, n, x) == 0);

    n = 5;
    x = 7;
    assert(SENTINEL_LINEAR_SEARCH(A, n, x) == NOT_FOUND);

    n = 5;
    x = 4;
    assert(SENTINEL_LINEAR_SEARCH(A, n, x) == 4);

    return 0;
}