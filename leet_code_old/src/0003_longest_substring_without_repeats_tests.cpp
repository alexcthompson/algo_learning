#define CATCH_CONFIG_MAIN

#include <string>
#include "catch2/catch.hpp"
#include "0003_longest_substring_without_repeats.hpp"


TEST_CASE ("all tests") {
    SECTION ("known results") {
        Solution s;
        std::string input;
        int res;

        input = "abcabcbb";
        res = 3;
        CHECK ( s.lengthOfLongestSubstring(input) == res );

        input = "bbbbb";
        res = 1;
        CHECK ( s.lengthOfLongestSubstring(input) == res );

        input = "pwwkew";
        res = 3;
        CHECK ( s.lengthOfLongestSubstring(input) == res );

        input = "abba";
        res = 2;
        CHECK ( s.lengthOfLongestSubstring(input) == res );
    }
}