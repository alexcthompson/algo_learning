#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "42_trapping_rain_water.hpp"

TEST_CASE ("all test cases") {
    SECTION ("known results") {
        std::vector<int> height;
        Solution s;

        height = {0,1,0,2,1,0,1,3,2,1,2,1};
        CHECK(s.trap(height) == 6);
    }
}