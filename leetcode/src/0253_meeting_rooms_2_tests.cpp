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

        std::vector<std::tuple<int,int>> unprocessed_input = {{5,10}, {15,30}, {0,30}, {2,4}};
        std::vector<Interval> answer = {Interval(0,30), Interval(2,4), Interval(5,10),
            Interval(15,30)};
        std::vector<Interval> processed_input = process_input(unprocessed_input);

        CHECK ( answer == processed_input );
    }

    SECTION ("known results") {
        Solution s;

        std::vector<std::tuple<int,int>> unprocessed_input = {{0,30}, {5,10}, {15,20}};
        int answer = 2;
        std::vector<Interval> processed_input = process_input(unprocessed_input);
        CHECK ( s.minMeetingRooms(processed_input) == answer );

        unprocessed_input = {{7,10}, {2,4}};
        answer = 1;
        processed_input = process_input(unprocessed_input);
        CHECK ( s.minMeetingRooms(processed_input) == answer );

    }
}