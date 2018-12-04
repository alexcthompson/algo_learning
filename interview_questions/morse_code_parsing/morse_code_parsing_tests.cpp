#define CATCH_CONFIG_MAIN

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "catch2/catch.hpp"
#include "morse_code_parsing.hpp"

using std::map;
using std::set;
using std::string;
using std::vector;

TEST_CASE ( "tests!" ) {


    SECTION ( "Test mc conversions" ) {
        string unparsed_words = "abcd xyz mpc";
        MCParser mcp(parseWords(unparsed_words));
        mcp.generate_single_word_dict();

        CHECK ( mc_from_string("abcd") == ".--...-.-.-.." );
        CHECK ( mc_from_string("xyz") ==  "-..--.----.." );
        CHECK ( mc_from_string("mpc") == "--.--.-.-." );

        map<string, set<vector<string>>> expected_map = {{"--.--.-.-.", {{"mpc"}}}, {"-..--.----..", {{"xyz"}}},
                                            {".--...-.-.-..", {{"abcd"}}}};
        CHECK ( mcp.get_single_word_dict() == expected_map );

    }

    SECTION ( "final results" ) {
        MCParser mcp(allEnglishWords);
        mcp.generate_single_word_dict();

        set<vector<string>> expected_result_set;
        expected_result_set = {{"he"}, {"eh"}};

        CHECK ( mcp.parse_mc(".....") == expected_result_set );

        expected_result_set = {{"a", "a"}, {"eta"}};
        CHECK ( mcp.parse_mc(".-.-") == expected_result_set );

        // the parsing {"in", "ire", "in", "eta", "in"}
        // becomes the string "inireinetain",
        // which becomes the mc_string "..-....-....-..-.-..-."

        string mc_string = "..-....-....-..-.-..-.";
        vector<string> expected_result_vec = {"in", "ire", "in", "eta", "in"};
        auto actual_result = mcp.parse_mc(mc_string);

        CHECK ( actual_result.find(expected_result_vec) != actual_result.cend() );
    }
}