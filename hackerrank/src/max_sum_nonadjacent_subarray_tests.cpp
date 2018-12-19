#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch2/catch.hpp"
#include "max_sum_nonadjacent_subarray.hpp"


struct Tcase {
    std::vector<int> arr;
    int result;
};


TEST_CASE ( "max sum of non-adjacent subarray" ) {

    SECTION ( "known correct results" ) {
        std::vector<Tcase> known_results;

        Tcase known_result;
        known_result.arr = {-4, 3, -2, 1, 1, 11};
        known_result.result = 15;
        known_results.push_back(known_result);

        known_result.arr = {-2, 1, 3, -4, 5};
        known_result.result = 8;
        known_results.push_back(known_result);


        known_result.arr = {3, 5, -7, 8, 10};
        known_result.result = 15;
        known_results.push_back(known_result);

        for (auto it = known_results.cbegin(); it != known_results.cend(); it++) {
            CHECK ( maxSubsetSum(it->arr) == it->result );
        }
    }
}