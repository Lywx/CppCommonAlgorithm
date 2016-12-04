#pragma once
#include <utility>

// @Summary: This is my solution after understanding the material. The
// profiling proves that this has somehow similar performance with solution b.
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
            //
            // The order of swapping (or assignment) (step = 4) is:
            //
            // +---+---+---+---+---+---+---+ outer 1st
            // -+---+---+---+---+---+---+--- outer 2nd
            // --+---+---+---+---+---+---+-- outer 3rd
            // ---+---+---+---+---+---+---+- ...
            //
            // Stop here.
            //
            // + = guaranteed 'knownIndex' position.
            //
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

            //// Another way to write this loop, just change the way index works.
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

// @Summary: This solution comes from 俞勇 数据结构_ 思想与实现, 1st, 2009.
template <typename T>
void ShellSortB(T *A, int n)
{
    for (int step = n / 2; step > 0; step /= 2)
    {
        // NOTE(Wuxiang): You could see this loop variable could range in
        // [step, step + 1, ..., n - 1]. The way of iterating is different from
        // solution a. This solution builds upon the fact after we insertion
        // sort the element before current index, the later sorting would not
        // affect (or re-sort) the sorted sub-array because of the while loop
        // entry condition.
        //
        // The order of swapping (or assignment) (step = 4) is:
        //
        // +---------------------------- outer 1st
        // -+--------------------------- outer 2nd
        // --+-------------------------- outer 3rd
        // ---+------------------------- ...
        // ----+------------------------
        // ?----+-----------------------
        // -?----+----------------------
        // --?----+---------------------
        // ---?----+--------------------
        // ----?----+-------------------
        // -----?----+------------------
        // ------?----+-----------------
        // ...
        // ----------------------?----+-
        // -----------------------?----+
        //
        // Stop here.
        //
        // + = guaranteed 'knownIndex' position.
        // ? = possible 'knownIndex' position

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
