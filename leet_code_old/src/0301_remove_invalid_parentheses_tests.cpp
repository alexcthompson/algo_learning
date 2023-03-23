#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER

#include <iostream>

#include "catch2/catch.hpp"
#include "0301_remove_invalid_parentheses.hpp"


TEST_CASE ( "all tests" ) {
    Solution s;

    // test strings
    std::string s1 = "()())()",
                s2 = "(a)())()",
                s3 = "((((((((",
                s4 = ")))))))))",
                s5 = "((())))))",
                s6 = "(()))((((()))",
                s7 = "(((k()((";


    SECTION ( "merge sets" ) {
        std::unordered_set<std::string> A = {"blah", "blub", "bubble", "trouble"};
        std::unordered_set<std::string> B = {"blub", "trouble", "tuba",
                                             "Aruba", "Jamaica", "Kokomo"};
        std::unordered_set<std::string> C = {"blah", "blub", "bubble", "trouble",
                                             "tuba", "Aruba", "Jamaica", "Kokomo"};

        merge_sets(A, B);
        REQUIRE ( A == C );
    }


    SECTION ( "paren assessment step" ) {
        CHECK ( s.count_paren_to_remove(s1) == std::tuple<int, int>(0,1) );
        CHECK ( s.count_paren_to_remove(s2) == std::tuple<int, int>(0,1) );
        CHECK ( s.count_paren_to_remove(s3) == std::tuple<int, int>(8,0) );
        CHECK ( s.count_paren_to_remove(s4) == std::tuple<int, int>(0,9) );
        CHECK ( s.count_paren_to_remove(s5) == std::tuple<int, int>(0,3) );
        CHECK ( s.count_paren_to_remove(s6) == std::tuple<int, int>(2,1) );
        CHECK ( s.count_paren_to_remove(s7) == std::tuple<int, int>(5,0) );
    }

    SECTION ( "remove invalid parens") {
        CHECK ( s.first_invalid_index(s1) == 4 );
        CHECK ( s.first_invalid_index(s2) == 5 );
        CHECK ( s.first_invalid_index(s3) == 8 );
        CHECK ( s.first_invalid_index(s4) == 0 );
        CHECK ( s.first_invalid_index(s5) == 6 );
        CHECK ( s.first_invalid_index(s6) == 4 );

        // test removing one right paren from left invalid segment
        std::unordered_set<std::string> expected_res;

        expected_res = {"()()()", "(())()"};
        CHECK ( s.remove_one_invalid_right(s1) == expected_res );

        expected_res = {"(a())()", "(a)()()"};
        CHECK ( s.remove_one_invalid_right(s2) == expected_res );

        expected_res = {"))))))))"};
        CHECK ( s.remove_one_invalid_right(s4) == expected_res );

        expected_res = {"((()))))"};
        CHECK ( s.remove_one_invalid_right(s5) == expected_res );

        expected_res = {"(())((((()))"};
        CHECK ( s.remove_one_invalid_right(s6) == expected_res );

        // test string flipper
        std::string expected_str = "()(()()";
        REQUIRE ( s.flip_string(s1) == expected_str );

        expected_str = "()(()(a)";
        REQUIRE ( s.flip_string(s2) == expected_str );

        expected_str = "(((((()))";
        REQUIRE ( s.flip_string(s5) == expected_str );

        expected_str = "((()))))((())";
        REQUIRE ( s.flip_string(s6) == expected_str );

        // test removal of one left paren from right invalid segment
        expected_res = {"((((((("};
        CHECK (s.remove_one_invalid_left(s3) == expected_res );

        expected_res = {"(()))(((()))"};
        CHECK (s.remove_one_invalid_left(s6) == expected_res );
    }

    SECTION ( "iteration of process") {
        std::unordered_set<std::string> input;
        std::unordered_set<std::string> expected_res;
        int left_to_remove, right_to_remove;

        input = {s1};
        left_to_remove = 0, right_to_remove = 1;
        expected_res = {"()()()", "(())()"};  // s1 = "()())()"
        CHECK ( s.fix_one_paren(input, left_to_remove, right_to_remove) == expected_res );

        left_to_remove = 2, right_to_remove = 1;
        input = s.fix_one_paren({s6}, left_to_remove, right_to_remove);
        expected_res = {"(()))((()))"};  // s6 = "(()))((((()))"
        CHECK ( s.fix_one_paren(input, left_to_remove, right_to_remove) == expected_res );

        input = {s7};
        left_to_remove = 5, right_to_remove = 0;
        expected_res = {"(k()","((k)"};

        for (int i = 0; i < 4; i++) {
            input = s.fix_one_paren(input, left_to_remove, right_to_remove);
            CHECK ( left_to_remove == 5 - i - 1 );
        }

        CHECK ( left_to_remove  == 1 );
        CHECK ( right_to_remove == 0 );
        CHECK ( input == expected_res );
    }

    SECTION ( "known results") {
        std::unordered_set<std::string> expected_res;
        std::unordered_set<std::string> actual_res;

        expected_res = {"()()()", "(())()"};

        // leetcode wants a vector returned, but it's better to check an unordered set
        // so we do this nonsense
        for (auto elem : s.removeInvalidParentheses(s1)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {"(a)()()", "(a())()"};
        for (auto elem : s.removeInvalidParentheses(s2)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {""};
        for (auto elem : s.removeInvalidParentheses(s3)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {""};
        for (auto elem : s.removeInvalidParentheses(s4)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {"((()))"};
        for (auto elem : s.removeInvalidParentheses(s5)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {"(())((()))"};
        for (auto elem : s.removeInvalidParentheses(s6)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();

        expected_res = {"k()","(k)"};
        for (auto elem : s.removeInvalidParentheses(s7)) {
            actual_res.insert(elem);
        }
        CHECK ( actual_res == expected_res );
        actual_res.clear();
    }

}