#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "0973_k_closest_points_to_origin.hpp"


TEST_CASE ("all tests") {

    SECTION ("known results") {
        Solution s;

        std::vector < std::vector<int> > points = {{1,3}, {2,2}, {1,0}, {0,1}, {5,5} };
        std::vector < std::vector<int> > result;
        std::vector < std::vector<int> > expected;

        result = s.kClosest(points, 0);
        CHECK( result.empty() );

        result = s.kClosest(points, 1);
        expected = {{1,0}};
        std::vector < std::vector<int> > expected2 = {{0,1}};
        CHECK( (result == expected2 || result == expected) );

        result = s.kClosest(points, 2);
        std::vector< std::vector< std::vector<int> > > expected_list = {{{1,0}, {0,1}}, {{0,1}, {1,0}}};
        CHECK( (result == expected_list[0] || result == expected_list[1]) );

    }
}