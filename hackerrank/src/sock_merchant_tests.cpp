/*
sock_merchant question from HackerRank:
https://www.hackerrank.com/challenges/sock-merchant/problem
*/

#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "sock_merchant.hpp"

TEST_CASE ( "TDD 4eva" ) {
    //

    SECTION ( "basics" ) {
        std::vector<int> sock_list{10, 20, 20, 10, 10, 30, 50, 10, 20};
        Sox socks(sock_list);

        CHECK( socks.get_socks() == sock_list );
        CHECK( socks.total_pairs() == 3 );
    }
}