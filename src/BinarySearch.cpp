#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
int BINARY_SEARCH(T A[], int n, T x)
{
    int middle;
    int begin = 0, end = n - 1;

    while (begin <= end)
    {
        middle = (begin + end) / 2;

        if (A[middle] == x)
        {
            return middle;
        }
        else
        {
            if (A[middle] < x)
            {
                // + 1 is important for avoiding problem when begin and end is
                // almost identical that middle will not be changed after
                // averaging.
                begin = middle + 1;
            }
            else
            {
                // - 1 has the same benefit of + 1 in the line above
                end = middle - 1;
            }
        }
    }

    return NOT_FOUND;
}

int BINARY_SEARCH(int A[], int n, int x)
{
    int middle;

    int begin = 0;
    int end   = n - 1;

    while (begin <= end)
    {
        middle = (begin + end) / 2;

        if (A[middle] == x)
        {
            return middle;
        }
        else
        {
            if (A[middle] < x)
            {
                begin = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
    }

    return NOT_FOUND;
}

int main(int argc, char **argv)
{
    int A[5] = {0, 1, 2, 3, 4};
    int n;
    int x;

    n = 5;
    x = 4;
    assert(BINARY_SEARCH(A, n, x) == 4);

    n = 5;
    x = 0;
    assert(BINARY_SEARCH(A, n, x) == 0);

    n = 5;
    x = 7;
    assert(BINARY_SEARCH(A, n, x) == NOT_FOUND);

    n = 5;
    x = 1;
    assert(BINARY_SEARCH(A, n, x) == 1);

    return 0;
}