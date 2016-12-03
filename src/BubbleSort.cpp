#include <utility>

void BubbleSort(int *A, int n)
{
    using std::swap;

    bool sortedAlready;

    // Only need n - 1 time, because at the n-th time, the second loop entry test
    // would be j < n - (n - 1) - 1 => j < 0 -- You would not enter the loop.
    for (int i = 0; i < n - 1; ++i)
    {
        sortedAlready = true;

        for (int j = 0; j < n - i - 1; ++j)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                sortedAlready = false;
            }
        }

        if (sortedAlready)
        {
            break;
        }
    }
}
