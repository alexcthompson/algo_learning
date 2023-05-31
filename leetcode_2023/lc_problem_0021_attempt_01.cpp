/*
Solution for LeetCode #N 'PROBLEM NAME'
https://leetcode.com/PROBLEM NAME!
Runtime: X ms for Y test cases, Zth percentile
Time complexity:
*/
#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define fo(i, n) for(int i=0;i<n;i++)
#define fr(i, is) for (auto& i:is)
typedef vector<int> vi;
typedef vector<string> vs;

/*******  Convenience functions for debug / testing *******/
template <typename T>
ostream& operator << (ostream& ostream, vector<T>& v) {
    ostream << "Vector< ";

    for (int i = 0; i < v.size(); i++) {
        ostream << v[i];

        if (i != v.size() - 1) {
            ostream << ", ";
        } else {
            ostream << ">";
        }
    }

    return ostream;
}

// LC Solution class goes here
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }
        }

        while (list1) {
            cur->next = list1;
            cur = list1;
            list1 = list1->next;
        }

        while (list2) {
            cur->next = list2;
            cur = list2;
            list2 = list2->next;
        }

        return res->next;
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    ListNode* list1;
    ListNode* list1;
    ListNode* correct_result;
    ListNode* result;

    // input = ;
    // correct_result = ;
    // result = ;

    // if (result == correct_result) {
    //     cout << "success:" << endl;
    // } else {
    //     cout << "**FAILURE**:" << endl;
    // }

    // cout << "input = " << input
    //      << ";\ncorrect_result = " << correct_result <<
    //      ";\nresult = " << result << endl << endl;
}