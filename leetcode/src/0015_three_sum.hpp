/*
Solution for LeetCode #15 'Three Sum'
https://leetcode.com/problems/3sum/
Runtime: X ms for Y test cases, Zth percentile (no further differentiation)
Time complexity: ...
*/

#include <set>
#include <vector>


class Solution {
public:
    std::set<std::vector<int>> two_sum(std::vector<int>& nums, int K, int start = 0);
    std::set<std::vector<int>> three_sum(std::vector<int>& nums);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
};


std::set<std::vector<int>> Solution::two_sum(std::vector<int>& nums, int K, int start) {
    // assumes it is given a sorted vector
    std::set<std::vector<int>> res;

    if (nums.size() - start <= 1) {
        return res;
    }

    int first_index = start;
    int second_index = nums.size() - 1;

    while (first_index < second_index) {
        // decrement to find potential match
        while (first_index < second_index && nums[first_index] + nums[second_index] > K) {
            second_index--;
        }

        if (first_index == second_index) {
            continue;
        }

        if (nums[first_index] + nums[second_index] == K) {
            res.emplace(std::vector<int>{nums[first_index], nums[second_index]});
        }

        while (first_index < nums.size() - 2 && nums[first_index] == nums[first_index + 1]) {
            first_index++;
        }

        first_index++;
    }

    return res;
}


std::set<std::vector<int>> Solution::three_sum(std::vector<int>& nums)  {
    std::set<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    if (nums.size() < 3) {
        return res;
    }

    int first_index = 0;

    while (first_index < nums.size() - 2) {
        auto extensions = two_sum(nums, -nums[first_index], first_index + 1);

        for (auto extension : extensions) {
            res.emplace(std::vector<int>{nums[first_index], extension[0], extension[1]});
        }

        while (nums[first_index] == nums[first_index] + 1) {
            first_index++;
        }

        first_index++;
    }

    return res;
}


std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
    std::set<std::vector<int>> set_res = three_sum(nums);
    std::vector<std::vector<int>> res;

    for (auto elem : set_res) {
        res.push_back(elem);
    }

    return res;
}