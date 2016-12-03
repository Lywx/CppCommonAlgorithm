#include <iostream>
#include <cassert>

using namespace std;

#define NOT_FOUND -1

template<typename T>
void SELECTION_SORT(T A[], int n)
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

void SELECTION_SORT(int A[], int n)
{
    for (auto i = 0; i < n; ++i)
    {
        auto minValue = A[i];
        auto minIndex = i;

        for (auto j = i + 1; j < n; ++j)
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

int main(int argc, char **argv)
{
    int A[] = { 9, 0, 1, 3, 4, 6, 7, 8, 2, 5 };
    int S[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n   = 10;

    SELECTION_SORT<int>(A, n);

    for (auto i = 0; i < n; ++i)
    {
        assert(A[i] == S[i]);
    }

    SELECTION_SORT(A, n);

    for (auto i = 0; i < n; ++i)
    {
        assert(A[i] == S[i]);
    }

    return 0;
}
