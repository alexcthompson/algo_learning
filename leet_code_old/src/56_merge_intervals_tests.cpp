#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "56_merge_intervals.hpp"


TEST_CASE ("all tests") {


    SECTION ("known outcomes") {
        Solution s;
        std::vector<Interval> input, answer;

        input = {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
        answer = {Interval(1,6), Interval(8,10), Interval(15,18)};
        CHECK ( s.merge(input) == answer );

        input = {Interval(1,4), Interval(4,5)};
        answer = {Interval(1,5)};
        CHECK ( s.merge(input) == answer );
    }
}