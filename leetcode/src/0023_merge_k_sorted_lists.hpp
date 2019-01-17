/*
Solution for LeetCode #23 'Merge k Sorted Lists'
https://leetcode.com/problems/merge-k-sorted-lists/
Runtime: 388 ms for 131 test cases, 11th percentile
Time complexity: O(n log n)
Note: I implemented ListNode and additional functions for LinkedList as an
exercise.
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList(ListNode* head_node = nullptr) { head_ = head_node; }
    ListNode* head_ = nullptr;
    void add_node(int val);
};

void LinkedList::add_node(int val) {
    ListNode* new_node = new ListNode(val);

    if (head_ == nullptr) {
        head_ = new_node;
        return;
    }

    ListNode* temp = head_;

    while (temp->next != nullptr) temp = temp->next;

    temp->next = new_node;
    new_node->next = nullptr;
}

std::ostream& operator << (std::ostream& stream, const LinkedList& llist) {
    ListNode* pos = llist.head_;

    stream << "head -> ";

    while (pos != nullptr) {
        stream << pos->val << " -> ";
        pos = pos->next;
    }

    stream << "tail";

    return stream;
}

bool operator == (const LinkedList& a, const LinkedList& b) {
    ListNode* aptr = a.head_;
    ListNode* bptr = b.head_;

    while (aptr != nullptr && bptr != nullptr) {
        if (aptr->val != bptr->val) return false;
        aptr = aptr->next;
        bptr = bptr->next;
    }

    if (aptr != bptr) return false;

    return true;
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b);
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
};

ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    LinkedList res;

    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            res.add_node(a->val);
            a = a->next;
        }
        else {
            res.add_node(b->val);
            b = b->next;
        }
    }

    while (a != nullptr) {
        res.add_node(a->val);
        a = a->next;
    }

    while (b != nullptr) {
        res.add_node(b->val);
        b = b->next;
    }

    return res.head_;
}

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
    /*
    as long as the vector is more than element, go through and merge adjacent
    pairs, and then truncate the list.
    */
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
        int N = lists.size() / 2;
        int rem = lists.size() % 2;

        for (int i = 0; i < N; i++) {
            lists[i] = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
        }

        if (rem == 1) lists[N] = lists[2*N];

        lists.resize(N + rem);
    }

    return lists[0];
}