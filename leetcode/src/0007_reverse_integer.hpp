/*
Solution for LeetCode #7 'Reverse Integer'
https://leetcode.com/problems/reverse-integer/
Runtime: 4 ms for 1032 test cases, 94th percentile (no further differentiation)
Time complexity: O(log N)
Space complexity: O(1) since we only consider int, not arbitrarily large N
*/

#include <cmath>


class Solution {
public:
    int reverse(int x) {
        long xl = long(x);
        long res = 0;

        if (x == 0) {
            return 0;
        }

        while (xl % 10 == 0) {
            xl /= 10;
        }

        while (xl != 0) {
            res *= 10;
            res += xl % 10;
            xl /= 10;
        }

        if (res > 2147483647 || res < -2147483648) {
            return 0;
        }

        return int(res);
    }
};