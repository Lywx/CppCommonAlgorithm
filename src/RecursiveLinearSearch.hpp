#pragma once

#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// A: an array.
// n: the number of elements in A to search through.
// x: the value being searched for.
// i: the index each iteration will look at
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