#include <utility>

// @Summary: This is my solution after understanding the material. And the
// profiling proves that this is much better than b solution, which is copied from
// 俞勇 数据结构_ 思想与实现, 1st, 2009 and this is trying to over-sort the sorted sub-array.
template <typename T>
void ShellSortA(T *A, int n)
{
    for (int step = n / 2; step >= 1; step /= 2)
    {
        // Step offset is the [0, 1, ..., step)
        for (int stepOffset = 0; stepOffset < step; ++stepOffset)
        {
            // NOTE(Wuxiang): The correct way is to use the insertions sort in
            // this loop rather than bubble sort. I made this mistake before
            // coming to the correct solution.
            for (int stepIndex = stepOffset;

                    // Compensate for satisfying the condition 'stepIndex + step < n'
                    // in next iteration.
                    stepIndex < n - step; stepIndex += step)
            {
                T newValue = A[stepIndex + step];
                int knownIndex = stepIndex;

                while(A[knownIndex] > newValue && knownIndex >= stepOffset)
                {
                    A[knownIndex + step] = A[knownIndex];
                    knownIndex -= step;
                }

                A[knownIndex + step] = newValue;
            }

            //// Another way to write this loop, just change the way index work.
            //// This solution is parallel to the InsertionSort.cpp
            // for (int stepIndex = stepOffset + step;
            //         stepIndex < n; stepIndex += step)
            // {
            //     T newValue = A[stepIndex];
            //     int knownIndex = stepIndex - step;

            //     while(A[knownIndex] > newValue && knownIndex >= stepOffset)
            //     {
            //         A[knownIndex + step] = A[knownIndex];
            //         knownIndex -= step;
            //     }

            //     A[knownIndex + step] = newValue;
            // }
        }
    }
}

template <typename T>
void ShellSortB(T *A, int n)
{
    for (int step = n / 2; step > 0; step /= 2)
    {
        for (int stepOffset = step; stepOffset < n; ++stepOffset)
        {
            int newValue = A[stepOffset];
            int knownIndex = stepOffset - step;
            while (A[knownIndex] > newValue && knownIndex >= 0)
            {
                A[knownIndex + step] = A[knownIndex];
                knownIndex -= step;
            }

            A[knownIndex + step] = newValue;
        }
    }
}
