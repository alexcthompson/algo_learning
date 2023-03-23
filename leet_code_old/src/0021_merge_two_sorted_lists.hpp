/*
Solution for LeetCode #21 'Merge Two Sorted Lists'
https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;

        if (l1 == NULL) {
            return l2;
        }

        if (l2 == NULL) {
            return l1;
        }

        if (l1->val <= l2->val) {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }

        return res;
    }
};
