#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "count_duplicates.hpp"


TEST_CASE ("all tests") {


    SECTION ("known results") {
        std::vector<int> input;
        int res;

        input = {1,3,1,4,5,6,3,2};
        res = 2;
        CHECK( countDuplicates(input) == res);

        input = {1,1,2,2,3};
        res = 2;
        CHECK( countDuplicates(input) == res);

        input = {1,2,3,4,5,6,7,8,9,10};
        res = 0;
        CHECK( countDuplicates(input) == res);

        input = {1,1,1,1,1,1};
        res = 1;
        CHECK( countDuplicates(input) == res);

        input = {1,1,1,1,1,1,2,2,2};
        res = 2;
        CHECK( countDuplicates(input) == res);
    }
}