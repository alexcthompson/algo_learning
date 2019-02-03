#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "distinct_pairs.hpp"


TEST_CASE ("all tests") {


    SECTION ("known results") {
        std::vector<int> input;
        int target;
        int res;

        input = {6,6,3,9,3,5,1};
        target = 12;
        res = 2;
        CHECK( numberOfPairs(input, target) == res);

        input = {6,12,3,9,3,5,1};
        target = 12;
        res = 1;
        CHECK( numberOfPairs(input, target) == res);
    }
}