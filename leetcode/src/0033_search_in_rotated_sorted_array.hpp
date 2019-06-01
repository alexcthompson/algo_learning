/*
Solution for LeetCode #33 'Search in Rotated Sorted Array'
https://leetcode.com/problems/search-in-rotated-sorted-array/
Runtime: 4 ms for 196 test cases, 95th percentile
Time complexity: O(n log n)
Space complexity: O(log n), excluding output, but completely neglible, and
could be O(1) since the only thing taking up space are the variables `middle`,
`left`, and `right`, which could be passed along to save space.
*/

#include <vector>


class Solution {
public:
    int sorted_binary_search(const std::vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] < target) {
                left = middle + 1;
            }
            else if (target < nums[middle]) {
                right = middle - 1;
            }
            else {
                return middle;
            }
        }

        return -1;
    }
    int search_range(const std::vector<int>& nums, int target, int left, int right) {
        // recursive search but without knowing that if it's sorted
        if (left == right) {
            return target == nums[left] ? left : -1;
        }

        if (nums[left] < nums[right]) {
            return sorted_binary_search(nums, target, left, right);
        }

        int middle = (left + right) / 2;

        if (nums[left] <= nums[middle]) {
            // the right half of the array is screwed up, but the left is fine
            if (nums[left] <= target && target <= nums[middle]) {
                return sorted_binary_search(nums, target, left, middle);
            }
            else {
                return search_range(nums, target, middle + 1, right);
            }
        }
        else {
            // the right half of the array is ok, but the left is screwed up
            if (nums[middle] <= target && target <= nums[right]) {
                return sorted_binary_search(nums, target, middle, right);
            }
            else {
                return search_range(nums, target, left, middle - 1);
            }
        }
    }
    int search(const std::vector<int>& nums, int target) {

        return nums.empty() ? -1 : search_range(nums, target, 0, nums.size() - 1);
    }
};