#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
void INSERTION_SORT(T A[], int n)
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

void INSERTION_SORT(int A[], int n)
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

int main(int argc, char **argv)
{
    int A[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
    int S[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n   = 10;

    INSERTION_SORT(A, n);

    for (auto i = 0; i < n; ++i)
    {
        assert(A[i] == S[i]);
    }

    return 0;
}
