/*
Lilah's repeated string, HackerRank problem found here:
https://www.hackerrank.com/challenges/repeated-string/problem
*/

#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "repeated_string.hpp"

TEST_CASE ( "tests!" ) {


    SECTION ( "examples" ) {
        CHECK ( repeatedString("aba", 10) == 7 );
        CHECK ( repeatedString("a", 1000000000000) == 1000000000000 );
        CHECK ( repeatedString("gfcaaaecbg", 547602) == 164280);
        CHECK ( repeatedString("kmretasscityylpdhuwjirnqimlkcgxubxmsxpypgzxtenweirknjtasxtvxemtwxuarabssvqdnktqadhyktagjxoanknhgilnm",
                               736778906400) == 51574523448);
    }
}