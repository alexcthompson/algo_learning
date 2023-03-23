/*
Solution for LeetCode #53 'Maximum Subarray'
https://leetcode.com/problems/maximum-subarray/
Runtime: X ms for Y test cases, Zth percentile (no further differentiation)
Time complexity:
*/

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int best = nums[0];
        int current = 0;

        for (int i = 0; i < nums.size(); i++) {
            current += nums[i];
            best = std::max(best, current);
            current = std::max(0, current);
        }

        return best;
    }
};