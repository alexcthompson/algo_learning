/*
Solution for LeetCode #973 'K Closest Points to Origin'
https://leetcode.com/problems/k-closest-points-to-origin/
Runtime: 312 ms for 83 test cases, 40th percentile
Time complexity: O(n log k)
*/

#include <queue>
#include <vector>

bool compare_points(const std::vector<int>& a, const std::vector<int>& b) {
    int lhs = a[0] * a[0] + a[1] * a[1];
    int rhs = b[0] * b[0] + b[1] * b[1];

    return lhs < rhs;
}

class ComparePoints {
public:
    bool operator() (const std::vector<int>& a, const std::vector<int>& b) {
        return compare_points(a, b);
    }
};

class Solution {
public:
    std::vector< std::vector<int> > kClosest(std::vector< std::vector<int> >& points, int K) {
        std::priority_queue<std::vector<int>, std::vector< std::vector<int> >, ComparePoints> pq;
        std::vector< std::vector<int> > result;

        if (K == 0) {
            return result;
        }

        for (auto point : points) {
            if (pq.size() < K) {
                pq.push(point);
            }
            else if (compare_points(point, pq.top())) {
                pq.push(point);
                pq.pop();
            }
        }

        // this yields the elements in order, but this could be faster by just reading off all the
        // elements in no particular order, if std::priority_queue allowed this.
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};