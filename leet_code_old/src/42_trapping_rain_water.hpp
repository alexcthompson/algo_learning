/*
Solution for LeetCode #42 'Trapping Rain Water'
https://leetcode.com/problems/trapping-rain-water/
Runtime: 42nd percentile
Time complexity: O(n)
*/

#include <stack>
#include <vector>

using std::vector;

struct LHeights {
    int index;
    int height;
};

class Solution {
private:
    int lake_bottom = 0;
    std::stack<LHeights> lheights;
    bool puddle_started = false;
    int total = 0;
public:
    int trap(vector<int>& height);
};

int Solution::trap(vector<int>& height) {
    if (height.size() <= 2) return 0;

    for (int i = 1; i < height.size(); i++) {
        if (height[i] < height[i-1]) {
            LHeights new_lheight{i-1, height[i-1]};
            lheights.push(new_lheight);
            lake_bottom = height[i];
        }

        if (height[i] > lake_bottom && !lheights.empty()) {
            while (!lheights.empty() && height[i] >= lheights.top().height) {
                LHeights left_edge = lheights.top();
                lheights.pop();
                total += (i - left_edge.index - 1) * (left_edge.height - lake_bottom);
                lake_bottom = left_edge.height;
            }

            if (!lheights.empty()) {
                total += (i - lheights.top().index - 1) * (height[i] - lake_bottom);
                LHeights new_lheight{i, height[i]};
                lheights.push(new_lheight);
            }
        }
    }

    return total;
}