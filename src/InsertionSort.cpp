#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

// @Summary: Insertion sort works in this way -- You gradually build up a sorted
// sub-array of size 'newIndex' + 1. Each time you try to insert element at the
// position of 'newIndex' to previously sorted sub-array while maintaining the
// order of new sub-array. Since the sub-array is sorted, you can do the linear
// probing and locate the right position to insert. Each insertion is done by
// gradually shifting the element in opposite direction (similar to the process
// of heap sort's percolating down or up). You can use swap in this process
// rather assignment in this implementation.
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