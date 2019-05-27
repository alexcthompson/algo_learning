/*
Solution for LeetCode #206 'Reverse Linked List'
https://leetcode.com/problems/reverse-linked-list/
Runtime: X ms for Y test cases, Zth percentile (no further differentiation)
Time complexity:
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct LinkedList {
    ListNode* head;
    ListNode* tail;
    void add_node(const int& val) {
        ListNode* new_node_ptr = new ListNode(val);

        if (head == NULL) {
            head = new_node_ptr;
            tail = new_node_ptr;
        }
        else {
            tail->next = new_node_ptr;
            tail = new_node_ptr;
        }
    }
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    LinkedList(const int& val) {
        ListNode* new_node_ptr = new ListNode(val);
        head = new_node_ptr;
        tail = new_node_ptr;
    }
    LinkedList(const std::vector<int>& vals) {
        head = NULL;
        tail = NULL;

        for (auto val : vals) {
            add_node(val);
        }
    }
};


std::ostream& operator << (std::ostream& ostream, const LinkedList& ll) {
    ostream << "LinkedList { ";
    ListNode* cur = ll.head;
    while (cur != NULL) {
        ostream << cur->val << " ";
        cur = cur->next;
    }

    ostream << "}";

    return ostream;
}


bool operator == (const LinkedList& l1, const LinkedList& l2) {
    ListNode* c1 = l1.head;
    ListNode* c2 = l2.head;

    while (c1 != NULL && c2 != NULL) {
        if (c1->val != c2->val) {
            return false;
        }

        c1 = c1->next;
        c2 = c2->next;
    }

    if (c1 != NULL || c2 != NULL) {
        return false;
    }

    return true;
}


bool operator != (const LinkedList& l1, const LinkedList& l2) {
    return !(l1 == l2);
}


class Solution {
public:
    void reverseList(LinkedList& ll) {
        if (ll.head == ll.tail) {
            return;
        }

        ListNode* cur = ll.head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        cur = ll.head;
        ll.head = ll.tail;
        ll.tail = cur;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        LinkedList ll;
        ll.head = head;
        ListNode* cur = head;

        while (cur->next != NULL) {
            cur = cur->next;
        }

        ll.tail = cur;

        reverseList(ll);

        return ll.head;
    }
};