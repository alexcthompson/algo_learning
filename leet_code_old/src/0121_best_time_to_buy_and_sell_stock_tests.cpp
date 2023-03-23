#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "0121_best_time_to_buy_and_sell_stock.hpp"


TEST_CASE ( "all tests" ) {
    Solution s;
    std::map<std::vector<int>, int> known_results = {
        {{7,1,5,3,6,4}, 5},
        {{7,6,4,3,1}, 0},
        {{1,10,-4,2,1,0,-20}, 9}
        };

    SECTION ( "known results" ) {
        for (auto res : known_results) {
            CHECK ( s.maxProfit(res.first) == res.second );
        }
    }
}