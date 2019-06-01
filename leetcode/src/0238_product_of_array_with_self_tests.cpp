#define CATCH_CONFIG_MAIN

#include <iostream>
#include <map>
// #include <vector>

#include "catch2/catch.hpp"
#include "0238_product_of_array_with_self.hpp"


template <typename T>
std::ostream& operator << (std::ostream& stream, const std::vector<T>& v) {
    stream << "Vector< ";

    for (auto val : v) {
        stream << val << " ";
    }

    stream << ">";

    return stream;
}

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& stream, const std::pair<const Key, Value>& kv) {
    stream << "kv[" << kv.first << ", " << kv.second << "]";

    return stream;
}


TEST_CASE ( "all tests" ) {
    Solution s;

    // input --> output
    std::map<std::vector<int>, std::vector<int>> examples = {
        {{1, 2, 3, 4}, {24, 12, 8, 6}},
        {{2, 5, 3, 7}, {105, 42, 70, 30}}
        };


    SECTION ( "known_results" ) {
        for (auto example : examples) {
            CHECK ( s.productExceptSelf(example.first) == example.second );
        }
    }
}