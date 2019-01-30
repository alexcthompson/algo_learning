/*
Solution for LeetCode #3 'Longest Substring Without Repeating Characters'
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Runtime: 20 ms for 987 test cases, 53rd percentile
Time complexity: O(n)
*/

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s);
};

int Solution::lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> recently_seen;
    int substr_pos = 0;
    int max_substr_len = 0;

    for (int i = 0; i < s.length(); i++) {
        if (substr_pos == i) {
            recently_seen[s[i]] = i;
            continue;
        }

        if (recently_seen.count(s[i]) == 0) {
            recently_seen[s[i]] = i;
        }
        else {
            max_substr_len = std::max(max_substr_len, i - substr_pos);

            for (int j = substr_pos; j <= recently_seen[s[i]] - 1; j++) {
                recently_seen.erase(s[j]);
            }

            substr_pos = recently_seen[s[i]] + 1;
            recently_seen[s[i]] = i;
        }
    }

    max_substr_len = std::max(max_substr_len, int(s.length() - substr_pos));

    return max_substr_len;
}