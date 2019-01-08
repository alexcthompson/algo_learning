/*
Solution for LeetCode #56 'Merge Intervals'
https://leetcode.com/problems/merge-intervals/
Runtime:
Time complexity: O(n log n)
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::vector;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool operator == (const Interval& a, const Interval& b) {
    return a.start == b.start && a.end == b.end;
}


std::ostream& operator << (std::ostream& stream, const Interval& in) {
    stream << "Interval(" << in.start << ", " << in.end << ")";
    return stream;
}


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals);
};


vector<Interval> Solution::merge(vector<Interval>& intervals) {
    if (intervals.size() <= 1) return intervals;

    vector<Interval> res;

    int left_count = 0, right_count = 0;
    std::priority_queue<int> left_coords, right_coords;

    for (auto interval : intervals) {
        left_coords.push(interval.start);
        right_coords.push(interval.end);
    }

    int right_edge = right_coords.top();
    int left_edge = left_coords.top();

    while (!right_coords.empty()) {
        int next_left = left_coords.top();
        int next_right = right_coords.top();

        if (right_count == 0) right_edge = next_right, left_edge = next_left;

        if (next_left <= next_right) {
            right_count++;
            right_coords.pop();
        }
        else if (next_right < next_left) {
            left_count++;
            left_coords.pop();
            left_edge = next_left;
        }

        if (left_count == right_count && !right_coords.empty() && right_coords.top() != left_edge) {
            res.push_back(Interval(left_edge, right_edge));
            left_count = 0, right_count = 0;
        }
    }

    // consider case with remaining left edges
    while (!left_coords.empty()) {
        left_edge = left_coords.top();
        left_coords.pop();
    }

    res.push_back(Interval(left_edge, right_edge));
    std::reverse(res.begin(), res.end());

    return res;
}
