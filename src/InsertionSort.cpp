#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
void InsertionSort(T A[], int n)
{
    for (int newIndex = 1; newIndex < n; ++newIndex)
    {
        T newValue = A[newIndex];

        int knownIndex = newIndex - 1;
        while(A[knownIndex] > newValue && knownIndex >= 0)
        {
            // Shift one position to the right for insertion of new value
            A[knownIndex + 1] = A[knownIndex];
            --knownIndex;
        }

        A[knownIndex + 1] = newValue;
    }
}

void InsertionSort(int A[], int n)
{
    for (int newIndex = 1; newIndex < n; ++newIndex)
    {
        int newValue = A[newIndex];

        int knownIndex = newIndex - 1;
        while(A[knownIndex] > newValue && knownIndex >= 0)
        {
            A[knownIndex + 1] = A[knownIndex];
            --knownIndex;
        }

        A[knownIndex + 1] = newValue;
    }
}