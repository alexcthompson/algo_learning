#define CATCH_CONFIG_MAIN

#include <iostream>
#include <sstream>

#include "catch2/catch.hpp"
#include "0206_reverse_linked_list.hpp"

/*
TODO write linked list reversal
*/

TEST_CASE ( "all tests" ) {
    Solution s;

    LinkedList a;
    a.add_node(6);
    a.add_node(7);
    a.add_node(8);

    SECTION ( "LinkedList" ) {

        LinkedList b;
        b.add_node(6);
        b.add_node(7);

        // check overload of ==
        REQUIRE ( a != b);

        b.add_node(9);
        REQUIRE ( a != b );

        b.tail->val = 8;
        REQUIRE ( a == b );

        b.add_node(11);
        REQUIRE ( a != b );

        // check overload of <<
        std::stringstream buf;
        std::streambuf* old = std::cout.rdbuf(buf.rdbuf());  // grab pointer to cout buff
        std::cout << b;
        std::string buffered = buf.str();
        std::cout.rdbuf(old);  // restore cout

        CHECK ( buffered == "LinkedList { 6 7 8 11 }" );

        // default constructor
        LinkedList c;
        CHECK ( c.head == NULL );
        CHECK ( c.tail == NULL );

        // single node constructor
        LinkedList d(6);
        CHECK ( d.head == d.tail );
        REQUIRE ( d.head != NULL );
        CHECK ( d.head->val == 6 );

        // vector constructor
        std::vector<int> inputs = {1,2,-3,-666};
        LinkedList e(inputs);
        CHECK ( e.head->next->next->val == -3 );
        CHECK ( e.head->next->next->next->val == -666 );
        CHECK ( e.tail->val == -666 );
    }

    SECTION ( "reversing LinkedList" ) {

        LinkedList b;
        b.add_node(8);
        b.add_node(7);
        b.add_node(6);

        s.reverseList(a);
        CHECK ( a == b );

        s.reverseList(a);  // a = 6 7 8, b = 8 7 6

        LinkedList res;
        res.head = s.reverseList(a.head);  // a = 8 7 6, a.head = 6
        ListNode* cur = res.head;

        while (cur->next != NULL) {
            cur = cur->next;
        }

        res.tail = cur;

        CHECK ( res == b );
    }
}