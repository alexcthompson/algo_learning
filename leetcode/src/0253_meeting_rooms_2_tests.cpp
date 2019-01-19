#define CATCH_CONFIG_MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "catch2/catch.hpp"

#include "0253_meeting_rooms_2.hpp"

TEST_CASE ("all tests") {


    SECTION ("interval tests") {
        Interval a(23,34);

        std::stringstream buffer;
        buffer <<  a;
        std::string output = buffer.str();
        CHECK ( output == "Interval( 23, 34)" );

        buffer.str(""); // clear the buffer

        Interval b(a.start, a.end);
        Interval c(a.start - 1, a.end);

        CHECK ( a == b );
        CHECK ( b != c );
    }

    SECTION ("known results") {
        Solution s;
        std::vector<std::tuple<int,int>> unprocessed_input = {{0,30}, {5,10}, {15,20}};

    }
}