/*
Solution for LeetCode #238 'Product of Array Except Self'
https://leetcode.com/problems/product-of-array-except-self/
Runtime: 36 ms for 17 test cases, 99th percentile
Time complexity: O(N)
Space complexity: O(1), if you don't count the output
*/

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);

        for (int i = nums.size() - 2; i >= 0; i--) {
            res[i] = res[i + 1] * nums[i + 1];
        }

        int product_so_far = 1;
        for (int i = 1; i < nums.size(); i++) {
            product_so_far *= nums[i - 1];
            res[i] *= product_so_far;
        }

        return res;
    }
};