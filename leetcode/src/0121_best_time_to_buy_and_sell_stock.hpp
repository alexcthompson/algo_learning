/*
Solution for LeetCode #121 'Best Time to Buy and Sell Stock'
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Runtime: 8 ms for 200 test cases, 92nd percentile (no further differentiation)
Time complexity: O(N)
Space complexity: O(1)
*/

#include <algorithm>
#include <vector>


class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int low = prices[0];
        int best = 0;

        for (auto price : prices) {
            low = std::min(low, price);
            best = std::max(best, price - low);
        }

        return best;
    }
};