#pragma once
#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template <typename T>
int RecursiveBinarySearch(T A[], T x, int begin, int end)
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
                return RecursiveBinarySearch(A, x, middle + 1, end);
            }
            else
            {
                return RecursiveBinarySearch(A, x, begin, middle - 1);
            }
        }
    }
    else
    {
        return NOT_FOUND;
    }
}

int RecursiveBinarySearch(int A[], int x, int begin, int end)
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
                return RecursiveBinarySearch(A, x, middle + 1, end);
            }
            else
            {
                return RecursiveBinarySearch(A, x, begin, middle - 1);
            }
        }
    }
    else
    {
        return NOT_FOUND;
    }
}
