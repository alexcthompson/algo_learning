/*
Solution for LeetCode #1 'Two Sum'
https://leetcode.com/problems/two-sum/
Runtime: 4 ms for 29 test cases, 100th to 60th percentile (no further differentiation)
Time complexity: O(n)
*/

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> complements;

    for (int i = 0; i < nums.size(); i++) {
        if (complements.count(target - nums[i])) {
            return {complements[target - nums[i]], i};
        }
        else {
            complements[nums[i]] = i;
        }
    }
    return {-1, -1};
}
