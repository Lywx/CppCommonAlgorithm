#pragma once
#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// A: an array.
// n: the number of elements in A to search through.
// x : the value being searched for.
int LinearSearch(int A[], int n, int x)
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
