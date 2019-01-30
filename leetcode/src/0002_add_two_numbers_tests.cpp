# define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "0002_add_two_numbers.hpp"

TEST_CASE ("all tests") {


    SECTION ("known results") {
        // Testcase 1
        // 342
        ListNode* l1 = new ListNode(2);
        ListNode* current = l1;

        ListNode* next = new ListNode(4);
        current->next = next;
        current = next;

        next = new ListNode(3);
        current->next = next;

        // 456
        ListNode* l2 = new ListNode(5);
        current = l2;

        next = new ListNode(6);
        current->next = next;
        current = next;

        next = new ListNode(4);
        current->next = next;

        Solution s;

        ListNode* res = s.addTwoNumbers(l1, l2);

        // 708
        CHECK ( res->val == 7 );
        REQUIRE ( res->next != NULL);
        CHECK ( res->next->val == 0 );
        REQUIRE ( res->next->next != NULL );
        CHECK ( res->next->next->val == 8 );

        // Testcase 2
        l1 = new ListNode(5);
        l2 = new ListNode(5);
        res = s.addTwoNumbers(l1, l2);

        CHECK ( res->val == 0 );
        REQUIRE ( res->next != NULL );
        CHECK ( res->next->val == 1 );
        REQUIRE ( res->next->next == NULL );
    }
}