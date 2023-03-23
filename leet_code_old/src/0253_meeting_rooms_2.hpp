/*
Solution for LeetCode #253 'Meeting Rooms II'
https://leetcode.com/problems/meeting-rooms-ii/
Runtime: 8 ms for 78 test cases, 99th percentile
Time complexity: O(n log n)
Notes: uncomment line 51-52 in order to submit to LeetCode,
and do not submit between lines 16 and 46
*/

#include <algorithm>
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

    std::sort(res.begin(), res.end(), [](Interval a, Interval b) { return a.start < b.start; });

    return res;
}


class Solution {
public:
    int minMeetingRooms(std::vector<Interval>& intervals) {
        // UNCOMMENT this line for LeetCode submission
        // std::sort(intervals.begin(), intervals.end(),
        //     [](Interval a, Interval b) {return a.start < b.start; });
        std::vector<Interval> last_meetings;

        for (auto interval : intervals) {
            int i = 0;
            bool placed = false;
            while (!placed && i < last_meetings.size()) {
                if (interval.start >= last_meetings[i].end) {
                    last_meetings[i] = interval;
                    placed = true;
                }

                i++;
            }

            if (!placed) { last_meetings.push_back(interval); }
        }

        return last_meetings.size();
    }
};