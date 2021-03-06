#pragma once
#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
void SelectionSort(T A[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        T   minValue = A[i];
        int minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (minValue > A[j])
            {
                minValue = A[j];
                minIndex = j;
            }
        }

        A[minIndex] = A[i];
        A[i] = minValue;
    }
}