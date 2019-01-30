/*
Solution for LeetCode #2 'Add Two Numbers'
https://leetcode.com/problems/add-two-numbers/
Runtime: X ms for Y test cases, Zth percentile (no further differentiation)
Time complexity:
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* start = new ListNode(-111);
    ListNode* current = start;
    ListNode* current_1 = l1;
    ListNode* current_2 = l2;
    int remainder = 0;

    while (current_1 != NULL and current_2 != NULL) {
        int sum = remainder + current_1->val + current_2->val;
        remainder = sum / 10;
        int val = sum % 10;
        ListNode* next = new ListNode(val);
        current->next = next;

        current = current->next;
        current_1 = current_1->next;
        current_2 = current_2->next;
    }

    while (current_1 != NULL) {
        int sum = remainder + current_1->val;
        remainder = sum / 10;
        int val = sum % 10;

        ListNode* next = new ListNode(val);
        current->next = next;

        current = current->next;
        current_1 = current_1->next;
    }

    while (current_2 != NULL) {
        int sum = remainder + current_2->val;
        remainder = sum / 10;
        int val = sum % 10;

        ListNode* next = new ListNode(val);
        current->next = next;

        current = current->next;
        current_2 = current_2->next;
    }

    if (remainder != 0) {
        ListNode* next = new ListNode(remainder);
        current->next = next;
    }

    return start->next;
}