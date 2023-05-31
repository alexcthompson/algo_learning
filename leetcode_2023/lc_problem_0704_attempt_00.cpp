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
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size());
    }

    int search(vector<int>& nums, int target, int start_pos, int end_pos) {
        int N = (end_pos + 1) - start_pos;
        
        if (N < 1) {
            return -1;
        } else if (N <= 2) {
            for (int pos = start_pos; pos < end_pos; pos++) {
                if (nums[pos] == target) {
                    return pos;
                }
            }

            return -1;
        }

        int mid_pos = (start_pos + end_pos) / 2;
        int num_mid = nums[mid_pos];

        if (num_mid == target) {
            return mid_pos;
        } else if (num_mid > target) {
            return search(nums, target, start_pos, mid_pos);
        } else {
            return search(nums, target, mid_pos + 1, end_pos);
        }
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    vector<int> nums;
    int target;
    int correct_result;
    int result;

    nums = {-1,0,3,5,9,12};
    target = 9;
    correct_result = 4;
    result = s.search(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << "; target = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

    nums = {-1,0,3,5,9,12};
    target = 2;
    correct_result = -1;
    result = s.search(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << "; target = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}