#define CATCH_CONFIG_MAIN

#include <string>
#include <vector>
#include "catch2/catch.hpp"
#include "mercedes_benz_05_huffman_decoder.hpp"


TEST_CASE ("all tests") {


    SECTION ("known results") {
        std::vector<string> codes;
        std::string encoded;
        std::string res;


        codes = {"a\t100100", "b\t100101", "c\t110001", "d\t100000", "[newline]\t111111",
            "p\t111110", "q\t000001"};
        encoded = "111110000001100100111111100101110001111110";
        res = "pqa\nbcp";

        CHECK( decode(codes, encoded) == res );
    }
}