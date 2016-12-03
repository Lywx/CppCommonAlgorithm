#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// A: an array.
// n: the number of elements in A to search through.
// x : the value being searched for.
int LINEAR_SEARCH(int A[], int n, int x)
{
    auto result = NOT_FOUND;

    for (auto i = 0; i < n; ++i)
    {
        if (A[i] == x)
        {
            result = i;
        }
    }

    return result;
}

int main(int argc, char **argv)
{
    int A[5] = { 0, 1, 2, 3, 4 };
    int n;
    int x;

    n = 5;
    x = 5;
    assert(LINEAR_SEARCH(A, n, x) == NOT_FOUND);

    n = 5;
    x = 0;
    assert(LINEAR_SEARCH(A, n, x) == 0);

    n = 5;
    x = 7;
    assert(LINEAR_SEARCH(A, n, x) == NOT_FOUND);

    n = 5;
    x = 4;
    assert(LINEAR_SEARCH(A, n, x) == 4);

    return 0;
}