#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "number_of_islands.hpp"


TEST_CASE( "island counting tests" ) {

    Solution soln;

    SECTION( "known results" ) {
        std::vector<std::vector<char>> grid;
        int expected_result;

        grid = {};
        expected_result = 0;
        CHECK ( soln.numIslands(grid) == expected_result );

        grid = {{'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}};
        expected_result = 1;
        CHECK ( soln.numIslands(grid) == expected_result );

        grid = {{'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}};
        expected_result = 3;
        CHECK ( soln.numIslands(grid) == expected_result );
    }
}