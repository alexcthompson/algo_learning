#define CATCH_CONFIG_MAIN

#include <tuple>

#include "catch2/catch.hpp"
#include "0033_search_in_rotated_sorted_array.hpp"


TEST_CASE ( "all tests" ) {
    Solution s;

    std::vector<std::tuple<std::vector<int>, int, int>> examples;

    std::vector<int> v = {4,5,6,7,0,1,2};
    int target = 0;
    int output = 4;
    examples.push_back({v, target, output   });

    v = {4,5,6,7,0,1,2};
    target = 3;
    output = -1;
    examples.push_back({v, target, output});

    v = {7, 0};
    target = 7;
    output = 0;
    examples.push_back({v, target, output});

    v = {7, 0};
    target = 3;
    output = -1;
    examples.push_back({v, target, output});

    v = {7, 0};
    target = 0;
    output = 1;
    examples.push_back({v, target, output});

    v = {};
    target = 5;
    output = -1;
    examples.push_back({v, target, output});

    SECTION ( "examples" ) {
        for (auto example : examples) {
            CHECK ( s.search(std::get<0>(example), std::get<1>(example))
                    == std::get<2>(example) );
        }
    }
}