#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template <typename T>
int RECURSIVE_BINARY_SEARCH(T A[], T x, int begin, int end)
{
    int middle = (begin + end) / 2;

    if (begin <= end)
    {
        if (A[middle] == x)
        {
            return middle;
        }
        else
        {
            if (A[middle] < x)
            {
                return RECURSIVE_BINARY_SEARCH(A, x, middle + 1, end);
            }
            else
            {
                return RECURSIVE_BINARY_SEARCH(A, x, begin, middle - 1);
            }
        }
    }
    else
    {
        return NOT_FOUND;
    }
}

int RECURSIVE_BINARY_SEARCH(int A[], int x, int begin, int end)
{
    int middle = (begin + end) / 2;

    if (begin <= end)
    {
        if (A[middle] == x)
        {
            return middle;
        }
        else
        {
            if (A[middle] < x)
            {
                return RECURSIVE_BINARY_SEARCH(A, x, middle + 1, end);
            }
            else
            {
                return RECURSIVE_BINARY_SEARCH(A, x, begin, middle - 1);
            }
        }
    }
    else
    {
        return NOT_FOUND;
    }
}

int main(int argc, char **argv)
{
    int A[5] = { 0, 1, 2, 3, 4 };
    int n;
    int x;

    n = 5;
    x = 4;
    assert(RECURSIVE_BINARY_SEARCH(A, x, 0, n) == 4);

    n = 5;
    x = 0;
    assert(RECURSIVE_BINARY_SEARCH(A, x, 0, n) == 0);

    n = 5;
    x = 7;
    assert(RECURSIVE_BINARY_SEARCH(A, x, 0, n) == NOT_FOUND);

    n = 5;
    x = 1;
    assert(RECURSIVE_BINARY_SEARCH(A, x, 0, n) == 1);

    return 0;
}