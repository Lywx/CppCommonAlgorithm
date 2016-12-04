#pragma once
#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// A: an array.
// n: the number of elements in A to search through.
// x : the value being searched for.
inline int BetterLinearSearch(int A[], int n, int x)
{
    for (auto i = 0; i < n; ++i)
    {
        if (A[i] == x)
        {
            return i;
        }
    }

    return NOT_FOUND;
}
