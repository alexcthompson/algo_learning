#define CATCH_CONFIG_MAIN

#include <iostream>
#include <stdexcept>

#include "catch2/catch.hpp"
#include "0021_merge_two_sorted_lists.hpp"



TEST_CASE ( "all tests" ) {
    Solution s;

    SECTION ( "examples" ) {
        ListNode* head   = new ListNode(1);
        head->next       = new ListNode(2);
        head->next->next = new ListNode(4);

        ListNode* head2   = new ListNode(1);
        head2->next       = new ListNode(3);
        head2->next->next = new ListNode(4);

        ListNode* res = s.mergeTwoLists(head, head2);
        std::vector<int> expected = {1,1,2,3,4,4};

        for (auto val : expected) {
            REQUIRE ( res != NULL );
            CHECK ( res->val == val );
            res = res->next;
        }

        CHECK ( res == NULL );
    }
}
