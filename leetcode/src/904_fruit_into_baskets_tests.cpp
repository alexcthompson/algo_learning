#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch2/catch.hpp"
#include "904_fruit_into_baskets.hpp"

TEST_CASE( "fruit into baskets" ) {


    SECTION( "known results" ) {
        Solution s;
        std::vector<int> tree;

        tree = {1};
        CHECK( s.totalFruit(tree) ==  1);

        s.reset_solution();
        tree = {1,2,1};
        CHECK( s.totalFruit(tree) ==  3);

        s.reset_solution();
        tree = {0,1,2,2};
        CHECK( s.totalFruit(tree) ==  3);

        s.reset_solution();
        tree = {1,2,3,2,2};
        CHECK( s.totalFruit(tree) ==  4);

        s.reset_solution();
        tree = {3,3,3,1,2,1,1,2,3,3,4};
        CHECK( s.totalFruit(tree) ==  5);

        s.reset_solution();
        tree = {0,0,1,1};
        CHECK( s.totalFruit(tree) == 4);
    }
}