#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "0007_reverse_integer.hpp"


TEST_CASE ( "all tests" ) {
    Solution s;

    std::map<int, int> correct_results = {
        {123, 321},
        {-123, -321},
        {120, 21},
        // below overflows as 2147483645 = 2^31 -3, and this now starts w/ 5
        {2147483645, 0},
        {2999999991, 0},
        {-2077777777, 0},
        {0, 0},
    };

    SECTION ( "correct_results" ) {
        for (auto res : correct_results) {
            CHECK ( s.reverse(res.first) == res.second );
        }
    }
}