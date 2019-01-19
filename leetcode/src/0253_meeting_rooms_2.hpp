/*
Solution for LeetCode #253 'Meeting Rooms II'
https://leetcode.com/problems/meeting-rooms-ii/
Runtime: X ms for Y test cases, Zth percentile
Time complexity:
*/

#include <iostream>
#include <tuple>
#include <vector>


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::ostream& operator << (std::ostream& stream, const Interval& interval) {
    stream << "Interval( " << interval.start << ", " << interval.end << ")";

    return stream;
}

bool operator == (const Interval& a, const Interval& b) {
    return a.start == b.start && a.end == b.end;
}

bool operator != (const Interval& a, const Interval& b) { return !(a == b); }

std::vector<Interval> process_input(const std::vector<std::tuple<int,int>>& intervals_in) {
    std::vector<Interval> res;

    for (auto val : intervals_in) {
        res.emplace_back(Interval(std::get<0>(val), std::get<1>(val)));
    }

    return res;
}


class Solution {
public:
    int minMeetingRooms(std::vector<Interval>& intervals) {
        return -1;
    }
};