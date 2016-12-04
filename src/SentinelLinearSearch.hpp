#pragma once
#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// A: an array.
// n: the number of elements in A to search through.
// x: the value being searched for.
template<typename T>
int SentinelLinearSearch(T A[], int n, T x)
{
    // Set up sentinel
    T ALast = A[n - 1];
    int i = 0;
    while(A[i] != x)
    {
        ++i;
    }

    // Restore sentinel
    A[n - 1] = ALast;

    bool foundPrev = i < n - 1;
    bool foundLast = ALast == x;
    return foundLast || foundPrev ? i : NOT_FOUND;
}