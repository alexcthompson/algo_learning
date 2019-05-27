#define CATCH_CONFIG_MAIN

#include <string>

#include "catch2/catch.hpp"
#include "0273_integer_to_english_words.hpp"


TEST_CASE ( "all tests" ) {
    Solution s;

    SECTION ( "examples" ) {
        int n;
        std::string expected;

        n = 123;
        expected = "One Hundred Twenty Three";
        CHECK( s.numberToWords(n) == expected );

        n = 12345;
        expected = "Twelve Thousand Three Hundred Forty Five";
        CHECK( s.numberToWords(n) == expected );

        n = 1234567;
        expected = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
        CHECK( s.numberToWords(n) == expected );

        n = 1234567891;
        expected = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
        CHECK( s.numberToWords(n) == expected );
    }
}