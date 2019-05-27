/*
Solution for LeetCode #301 'Remove Invalid Parentheses'
https://leetcode.com/problems/remove-invalid-parentheses/
Runtime: 82 ms for 126 test cases, 82th percentile
Time complexity: I think the worst case is bad, roughly O( C(N, K) ) where N is
the number of parentheses and K is the number of invalid parentheses.
*/

#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


// included for debugging
template <typename T>
std::ostream& operator << (std::ostream& ostream, const std::unordered_set<T>& us) {
    ostream << "USET { ";

    for (auto elem : us) {
        std::cout << elem << " ";
    }

    ostream << "}";

    return ostream;
}


template <typename T>
void merge_sets(std::unordered_set<T>& A, std::unordered_set<T>& B) {
    for (auto elem : B) {
        A.insert(elem);
    }
}


// TODO: refactor to bring the partical results sets, left_to_remove, and
// right_to_remove within this class.  Or create a container for given string
// which does this.
class Solution {
public:
    // counts the min # of left and right parens that must be removed to make a valid expression
    std::tuple<int, int> count_paren_to_remove(const std::string& s);

    // starting from the left, finds the first index at which the expression req removing a ')'
    int first_invalid_index(const std::string& s);

    // removes one invalid right or left paren
    std::unordered_set<std::string> remove_one_invalid_right(const std::string& s);
    std::string flip_string(const std::string& s);
    std::unordered_set<std::string> remove_one_invalid_left(const std::string& s);

    // given an unordered_set of strings, derived from the original invalid one
    // iterate forward by improving each string by one paren and yielding that set
    std::unordered_set<std::string> fix_one_paren(const std::unordered_set<std::string>& pstrings,
                                                  int& left_to_remove, int& right_to_remove);

    // does the same thing, but for LeetCode
    std::vector<std::string> removeInvalidParentheses(std::string s);
};


std::tuple<int, int> Solution::count_paren_to_remove(const std::string& s) {
    int left_to_remove = 0, right_to_remove = 0;

    for (auto c : s) {
        if ( c == '(' ) {
            left_to_remove++;
        }
        else if ( c == ')' ) {
            if (left_to_remove > 0) {
                left_to_remove--;
            }
            else if (left_to_remove == 0) {
                right_to_remove++;
            }
        }
    }

    return std::tuple<int, int>(left_to_remove, right_to_remove);
}


int Solution::first_invalid_index(const std::string& s) {
    int pos = -1;
    int left_count = 0;

    while (left_count >= 0 && pos < int(s.size())) {
        pos++;

        if (s[pos] == '(') {
            left_count++;
        }
        else if (s[pos] == ')') {
            left_count--;
        }
    }

    return pos;
}


std::unordered_set<std::string> Solution::remove_one_invalid_right(const std::string& s) {
    std::unordered_set<std::string> res;
    int end_remove = first_invalid_index(s);
    int pos = 0;

    while (pos <= end_remove) {
        while (s[pos] != ')') {
            pos++;
        }

        res.insert(s.substr(0, pos) + s.substr(pos + 1));

        while (s[pos] == ')') {
            pos++;
        }

        pos++;
    }

    return res;
}


std::string Solution::flip_string(const std::string& s) {
    std::string s_rev;

    for (auto it = s.rbegin(); it < s.rend(); it++) {
        if (*it == '(') {
            s_rev += ')';
        }
        else if (*it == ')') {
            s_rev += '(';
        }
        else {
            s_rev += *it;
        }
    }

    return s_rev;
}


std::unordered_set<std::string> Solution::remove_one_invalid_left(const std::string& s) {
    std::string s_rev = flip_string(s);

    std::unordered_set<std::string> rev_res = remove_one_invalid_right(s_rev);
    std::unordered_set<std::string> res;

    for (auto elem : rev_res) {
        res.insert(flip_string(elem));
    }

    return res;
}


std::unordered_set<std::string> Solution::fix_one_paren(
    const std::unordered_set<std::string>& pstrings, int& left_to_remove, int& right_to_remove)
{
    std::unordered_set<std::string> res;

    if (left_to_remove > 0) {
        for (auto pstring : pstrings) {
            auto temp = remove_one_invalid_left(pstring);
            merge_sets(res, temp);
        }
        left_to_remove--;
    }
    else if (right_to_remove > 0) {
        for (auto pstring : pstrings) {
            auto temp = remove_one_invalid_right(pstring);
            merge_sets(res, temp);
        }
        right_to_remove--;
    }

    return res;
}


std::vector<std::string> Solution::removeInvalidParentheses(std::string s) {
    std::unordered_set<std::string> res = {s};
    std::tuple<int, int> parens_to_delete = count_paren_to_remove(s);
    int left_to_remove  = std::get<0>(parens_to_delete);
    int right_to_remove = std::get<1>(parens_to_delete);

    while (left_to_remove > 0 || right_to_remove > 0) {
        res = fix_one_paren(res, left_to_remove, right_to_remove);
    }

    return std::vector<std::string>(res.begin(), res.end());
}