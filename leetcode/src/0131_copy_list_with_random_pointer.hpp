/*
Solution for LeetCode #131 'Copy List with Random Pointer'
https://leetcode.com/problems/copy-list-with-random-pointer/
Runtime: 28 ms for 9 test cases, 98th percentile
Time complexity: O(N)
Space complexity: O(N)
*/

#include <unordered_set>


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* cur_res = NULL;
        Node* res = NULL;
        Node* prev = NULL;

        // pass through the list starting with head, and recreate the list
        // with random set to NULL, but keep track of index in both lists
        int i = 0;
        std::unordered_map<Node*, Node*> head_ptr_to_res_ptr;

        while (cur) {
            cur_res = new Node(cur->val, NULL, NULL);

            if (prev) {
                prev->next = cur_res;
            }
            else {
                // first node, so set the head pointer
                res = cur_res;
            }

            // record indices
            head_ptr_to_res_ptr[cur] = cur_res;

            // prep iteration
            cur = cur->next;
            prev = cur_res;
            i++;
        }

        // the first pass built a copy of the vals and ordering, now for random
        cur = head;
        cur_res = res;

        while (cur) {
            cur_res->random = head_ptr_to_res_ptr[cur->random];
            cur_res = cur_res->next;
            cur = cur->next;
        }

        return res;
    }
};