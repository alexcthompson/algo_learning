/*
Solution for LeetCode #N 'PROBLEM NAME'
https://leetcode.com/problems/two-sum/
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
        unordered_map<int, int> seen;
        vector<int> indices;
        int pos = 0;

        while (indices.size() == 0) {
            int cur = nums[pos];

            if (seen.count(cur) > 0) {
                return {seen[cur], pos};
            }

            seen[target - cur] = pos;
            pos++;
        }

        return {-1, -1};  // necessary to avoid compile error
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    vi nums;
    int target;
    vector<int> result;
    vector<int> correct_result;

    nums = {2,7,11,15};
    target = 9;
    correct_result = {0,1};

    result = s.twoSum(nums, target);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "nums = " << nums << ";\ntarget = " << target
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}