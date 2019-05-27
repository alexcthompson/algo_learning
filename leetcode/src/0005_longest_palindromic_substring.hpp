/*
Solution for LeetCode #5 'Longest Palindromic Substring'
https://leetcode.com/problems/longest-palindromic-substring/
Runtime: X ms for Y test cases, Zth percentile
Time complexity:
*/
#include <queue>
#include <string>
#include <tuple>

bool is_palindrome(std::string phrase) {
    int pos = 0;

    while (pos <= long(phrase.size()) / 2 - 1) {
        if (phrase[pos] != phrase[phrase.size() - pos - 1]) {
            return false;
        }
        pos += 1;
    }

    return true;
}

class Solution {
public:
    std::string longestPalindrome(std::string s);
};

std::string Solution::longestPalindrome(std::string s) {
    // idea: maintain a queue of items to check
    // take the next element (and remove it)
    // if it's a palindrome, note it as the best
    // and add its expansion to the list to check
    // else do nothing
    // track palindromes to check as start_pos and length
    if (s.size() == 0) {
        return "";
    }
    else if (s.size() == 1) {
        return s;
    }

    std::string best_pali = s.substr(0,1);
    std::queue<std::tuple<int, int>> to_check;

    int current_pos = 0;

    // populate non-trivial palindromes to check of length 2 and 3
    for (int increment = 2; increment <= 3; increment++) {
        for (current_pos = 0; current_pos + increment <= s.size(); current_pos++) {
            std::tuple<int,int> new_val = {current_pos, increment};
            to_check.push(new_val);
        }
    }

    // bottom up solution
    while (!to_check.empty()) {
        auto candidate_tuple = to_check.front();
        int start_pos = std::get<0>(candidate_tuple);
        int length = std::get<1>(candidate_tuple);
        std::string candidate = s.substr(start_pos, length);

        to_check.pop();

        if (is_palindrome(candidate)) {
            if (length > best_pali.size()) {
                best_pali = candidate;
            }

            if (start_pos > 0 && start_pos + length + 1 <= s.size()) {
                to_check.push(std::make_tuple<int,int>(start_pos - 1, length + 2));
            }
        }
    }

    return best_pali;
}