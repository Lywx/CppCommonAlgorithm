#include "catch.hpp"

#include <iostream>
#include <string>

#include <LinearSearch.cpp>
#include <BetterLinearSearch.cpp>
#include <SentinelLinearSearch.cpp>

using namespace std;

void RequireFound(int *A, int n, int x, int i, int line)
{
    INFO("Line number: " + to_string(line));

    REQUIRE(LinearSearch(A, n, x)         == i);
    REQUIRE(BetterLinearSearch(A, n, x)   == i);
    REQUIRE(SentinelLinearSearch(A, n, x) == i);
}

void RequireNotFound(int *A, int n, int x, int line)
{
    INFO("Line number: " + to_string(line));

    REQUIRE(LinearSearch(A, n, x)         == NOT_FOUND);
    REQUIRE(BetterLinearSearch(A, n, x)   == NOT_FOUND);
    REQUIRE(SentinelLinearSearch(A, n, x) == NOT_FOUND);
}

#define REQUIRE_NOT_FOUND(A, n, x) RequireNotFound(A, n, x, __LINE__);
#define REQUIRE_FOUND(A, n, x, i) RequireFound(A, n, x, i, __LINE__);

TEST_CASE("Search Test", "")
{
    SECTION("")
    {
        int A[5] = { 0, 1, 2, 3, 4 };
        int n;
        int x;

        n = 5;
        x = 5;
        REQUIRE_NOT_FOUND(A, n, x);

        n = 5;
        x = 7;
        REQUIRE_NOT_FOUND(A, n, x);

        n = 5;
        x = 0;
        REQUIRE_FOUND(A, n, x, 0);

        n = 5;
        x = 4;
        REQUIRE_FOUND(A, n, x, 4);
    }
}
