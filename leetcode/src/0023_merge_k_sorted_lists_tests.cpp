#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <iostream>
#include <vector>
#include "catch2/catch.hpp"
#include "0023_merge_k_sorted_lists.hpp"


TEST_CASE("all tests") {

    SECTION("LinkedList class") {
        LinkedList l;

        std::vector<int> answer = {11, 12, -66};

        for (int i : answer) {
            l.add_node(i);
        }

        ListNode* s = l.head_;
        int i = 0;

        while (s != nullptr) {
            CHECK ( s->val == answer[i++] );
            s = s->next;
        }
    }

    SECTION("merge function") {
        Solution s;
        LinkedList a;
        LinkedList b;

        std::vector<int> a_elems = {1,2,3,5};
        std::vector<int> b_elems = {0,1,2,4,7};

        for (int i : a_elems) a.add_node(i);
        for (int i : b_elems) b.add_node(i);

        std::vector<int> answer = a_elems;
        answer.insert(answer.cend(), b_elems.cbegin(), b_elems.cend());
        std::sort(answer.begin(), answer.end());

        LinkedList answer_ll;
        for (int i : answer) answer_ll.add_node(i);

        ListNode* res = s.mergeTwoLists(a.head_, b.head_);
        LinkedList res_ll(res);

        CHECK( res_ll == answer_ll );
    }

    SECTION("known results") {
        Solution s;

        std::vector<ListNode*> input;
        std::vector<std::vector<int>> vals = {{1,4,5}, {1,3,4}, {2,6}};

        for (auto v : vals) {
            LinkedList l;
            for (auto i : v) l.add_node(i);
            input.push_back(l.head_);
        }

        std::vector<int> answer = {1,1,2,3,4,4,5,6};
        LinkedList answer_ll;
        for (int i : answer) answer_ll.add_node(i);

        ListNode* res = s.mergeKLists(input);
        LinkedList res_ll(res);

        CHECK( res_ll == answer_ll);

        // test for empty list
        input = {};
        res_ll.head_ = s.mergeKLists(input);

        CHECK( res_ll == nullptr );
    }
}