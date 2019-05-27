#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch2/catch.hpp"
#include "0053_maximum_subarray.hpp"


TEST_CASE( "all tests" ) {
    Solution s;

    SECTION ( "exemplars" ) {
        std::vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
        int expected = 6;

        CHECK ( s.maxSubArray(input) == expected );

        input = {1};
        expected = 1;
        CHECK ( s.maxSubArray(input) == expected );

        input = {-1};
        expected = -1;
        CHECK ( s.maxSubArray(input) == expected );

        input = {-2, 1};
        expected = 1;
        CHECK ( s.maxSubArray(input) == expected );
    }
}