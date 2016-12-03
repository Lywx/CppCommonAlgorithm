#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template <typename T>
int RECURSIVE_LINEAR_SEARCH(T A[], int n, int i, T x)
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
        return RECURSIVE_LINEAR_SEARCH(A, n, i + 1, x);
    }
}

// A: an array.
// n: the number of elements in A to search through.
// x: the value being searched for.
// i: the index each iteration will look at
int RECURSIVE_LINEAR_SEARCH(int A[], int n, int i, int x)
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
        return RECURSIVE_LINEAR_SEARCH(A, n, i + 1, x);
    }
}

int main(int argc, char **argv)
{
    int A[5] = {0, 1, 2, 3, 4};
    int n;
    int i;
    int x;

    n = 5;
    i = 0;
    x = 4;
    assert(RECURSIVE_LINEAR_SEARCH(A, n, i, x) == 4);

    n = 5;
    i = 0;
    x = 0;
    assert(RECURSIVE_LINEAR_SEARCH(A, n, i, x) == 0);

    n = 5;
    i = 0;
    x = 7;
    assert(RECURSIVE_LINEAR_SEARCH(A, n, i, x) == NOT_FOUND);

    n = 5;
    i = 4;
    x = 4;
    assert(RECURSIVE_LINEAR_SEARCH(A, n, i, x) == 4);

    return 0;
}