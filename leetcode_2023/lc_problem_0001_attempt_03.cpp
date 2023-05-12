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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;

        fo(pos, nums.size()) {
            int num = nums[pos];
            auto match = seen.find(num);

            if (match != seen.end()) {
                return {match->second, pos};
            }

            seen[target - num] = pos;
        }
        
        return {-1};
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    vi nums;
    int target;
    vi correct_result;
    vi result;

    nums = {2,7,11,15};
    target = 9;
    correct_result = {0,1};
    result = s.twoSum(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << "; target = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
    
    nums = {3,2,4};
    target = 6;
    correct_result = {1,2};
    result = s.twoSum(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << "; target = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

    nums = {3,3};
    target = 6;
    correct_result = {0,1};
    result = s.twoSum(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << "; target = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}