#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch2/catch.hpp"
#include "0015_three_sum.hpp"

/*Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

TEST_CASE( "all tests" ) {
    Solution s;

    SECTION ( "two sum" ) {
        std::vector<int> nums = {-1, 0, 1, 2, -1, -1, 4};
        std::sort(nums.begin(), nums.end());

        int K = 0;
        std::set<std::vector<int>> expected = {{-1, 1}};
        CHECK ( s.two_sum(nums, K) == expected );

        K = 1;
        expected = {{-1, 2}, {0, 1}};
        CHECK ( s.two_sum(nums, K) == expected );

        K = 2;
        expected = {{0, 2}};
        CHECK ( s.two_sum(nums, K) == expected );

        K = 3;
        expected = {{-1, 4}, {1, 2}};
        CHECK ( s.two_sum(nums, K) == expected );
    }

    SECTION ( "three sum") {
        std::vector<int> input = {-1, 0, 1, 2, -1, -4};
        std::set<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};

        CHECK (s.three_sum(input) == expected);

        std::vector<std::vector<int>> expected_vector = {{-1, -1, 2}, {-1, 0, 1}};
        CHECK (s.threeSum(input) == expected_vector);
    }
}