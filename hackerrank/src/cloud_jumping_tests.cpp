#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "cloud_jumping.hpp"

TEST_CASE ( "cloud jumping tests!" ) {
    SECTION ( "check correct computation" ) {
        std::vector<int> test_data = {0,1,0,0,0,1,0};
        CHECK ( jumpingOnClouds(test_data) == 3);

        test_data = {0,1,0,0,1,0,0};
        CHECK (jumpingOnClouds(test_data) == 4);
    }
}