#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "0001_two_sum.hpp"

TEST_CASE ("all tests") {


    SECTION ("known results") {
        Solution s;
        std::vector<int> input;
        int target;
        std::vector<int> result;

        input = {2,7,11,15};
        target = 9;
        result = {0,1};
        CHECK ( s.twoSum(input, target) == result );
    }
}
