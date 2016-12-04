#pragma once
#include <utility>

void PercolateDown(int *A, int i, int n)
{
    // NOTE(Wuxiang): The heap is zero index based.
    //
    // Parent      = (i - 1) / 2
    // Left child  = 2 * i + 1.
    // Right child = 2 * i + 2
    using std::swap;

    int indexLargerChild;
    for (int index = i;

            // Left child exists
            index * 2 + 1 < n; index = indexLargerChild)
    {
        indexLargerChild = 2 * index + 1;
        if (indexLargerChild < n - 1 && A[indexLargerChild] < A[indexLargerChild + 1])
        {
            ++indexLargerChild;
        }

        if (A[index] < A[indexLargerChild])
        {
            swap(A[index], A[indexLargerChild]);
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *A, int n)
{
    using std::swap;

    // Build heap
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        PercolateDown(A, i, n);
    }

    // Iterate every node except the head node
    for (int i = n - 1; i > 0; --i)
    {
        swap(A[0], A[i]);

        PercolateDown(A, 0, i);
    }
}
