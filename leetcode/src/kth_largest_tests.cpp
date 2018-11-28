#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <iostream>
#include <vector>

#include "catch2/catch.hpp"
#include "kth_largest.hpp"


TEST_CASE ( "Main body of tests" ) {

    std::vector<int> test_data = {1,3,5,-1,7,6,4,2,13,22,-11,14,21};

    min_heap heap;
    KthLargest topk(5, test_data);

    SECTION ( "Test Heap" ) {
        CHECK ( heap.len() == 0 );
        CHECK ( heap.parent_pos(5)  == 2 );
        CHECK ( heap.parent_pos(10) == 4 );
        CHECK ( heap.parent_pos(0)  == -999 );

        auto it = test_data.begin();

        while (it < test_data.cbegin() + 3) {
            heap.insert(*it);
            it++;
        }

        CHECK ( heap.len() == 3 );
        CHECK ( heap.min() == 1 );

        heap.insert(*it);
        it++;

        CHECK ( heap.min() == -1 );

        auto remaining_test_data = std::vector<int>(it, test_data.end());

        heap.heapify(remaining_test_data);

        CHECK ( heap.len() == test_data.size() );
        CHECK ( heap.min() == -11 );
        CHECK ( heap.extract() == -11 );
        CHECK ( heap.extract() == -1 );
        CHECK ( heap.extract() == 1 );

    }

    SECTION ( "Test KthLargest" ) {
        CHECK ( topk.add(25) == 13 );
        CHECK ( topk.add(10) == 13 );
        CHECK ( topk.add(13) == 13 );
        CHECK ( topk.add(14) == 14 );
        CHECK ( topk.add(20) == 14 );
        CHECK ( topk.add(60) == 20 );

        // failed testcase from leetcode
        std::vector<int> lc_test_data;
        KthLargest lc_testcase(1, lc_test_data);
        CHECK ( lc_testcase.add(-3) == -3 );
        CHECK ( lc_testcase.add(-2) == -2 );
        CHECK ( lc_testcase.add(-4) == -2 );
        CHECK ( lc_testcase.add( 0) ==  0 );
        CHECK ( lc_testcase.add( 4) ==  4 );
    }
}