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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* next1 = list1;
        ListNode* next2 = list2;
        ListNode* res_begin = nullptr;
        ListNode* res_end = nullptr;

        while (next1 && next2) {
            if (next1->val <= next2->val) {
                if (res_end) res_end->next = next1;

                res_end = next1;
                next1 = next1->next;
            } else {
                if (res_end) res_end->next = next2;

                res_end = next2;
                next2 = next2->next;
            }

            if (!res_begin) {
                res_begin = res_end;
            }
        }

        while (next1) {  
            if (res_end) res_end->next = next1;

            res_end = next1;
            next1 = next1->next;

            if (!res_begin) {
                res_begin = res_end;
            }        
        }


        while (next2) {

            if (res_end) res_end->next = next2;

            res_end = next2;
            next2 = next2->next;
 
            if (!res_begin) {
                res_begin = res_end;
            }
       }

        cout << "returning from mergeTwoLists" << endl;
        return res_begin;
    }
};
// LC Solution class goes here

ListNode* listNodesFromVec(vector<int> nums) {
    ListNode* res = nullptr;
    ListNode* res_end = nullptr;

    for (auto num : nums) {
        ListNode* new_node = new ListNode(num);

        if (res_end) res_end->next = new_node;
        
        res_end = new_node;

        if (!res) res = res_end;
    }

    return res;
}

vector<int> vecFromListNodes(ListNode* start) {
    ListNode* cur = start;
    vector<int> res;

    while (cur) {
        res.push_back(cur->val);
        cur = cur->next;
    }

    return res;
}

int main() {
    Solution s;

    ListNode* list1;
    ListNode* list2;
    vector<int> correct_result;
    vector<int> result;

    list1 = listNodesFromVec({1,2,4});
    list2 = listNodesFromVec(vector<int>{1,3,4});
    correct_result = {1,1,2,3,4,4};
    result = vecFromListNodes(s.mergeTwoLists(list1, list2));

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}