#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "valley_counting.hpp"

TEST_CASE ( "all the tests :)" ) {

    CHECK ( countingValleys(8, "UDDDUUDU") == 1);
    CHECK ( countingValleys(10, "DDUUDUDUDU") == 4 );
    CHECK ( countingValleys(8, "UUUDDUDD") == 0 );
    CHECK ( countingValleys(8, "UDDDUDUU") == 1 );
}