/*
Solution for LeetCode #N 'PROBLEM NAME'
https://leetcode.com/PROBLEM NAME!
Runtime: X ms for Y test cases, Zth percentile
Time complexity:
*/
#include <bits/stdc++.h>

using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define fo(i, n) for(int i=0;i<n;i++)
#define fr(i, is) for (auto& i:is)
typedef vector<int> vi;
typedef vector<string> vs;

/*******  Convenience functions for debug / testing *******/
template <typename T>
ostream& operator << (ostream& ostream, vector<T>& v) {
    ostream << "Vector< ";

    for (int i = 0; i < v.size(); i++) {
        ostream << v[i];

        if (i != v.size() - 1) {
            ostream << ", ";
        } else {
            ostream << ">";
        }
    }

    return ostream;
}

// LC Solution class goes here
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (auto cur_str : strs) {
            min_length = min(static_cast<int>(cur_str.length()), min_length);
        }

        return longestCommonPrefix(strs, 0, strs.size());
    }

    string longestCommonPrefix(vector<string>& strs, int start_pos, int end_pos) {
        if (start_pos + 1 == end_pos) return strs[start_pos];

        int split_pos = (start_pos + end_pos) / 2;
        string prefix_left = longestCommonPrefix(strs, start_pos, split_pos);
        string prefix_right = longestCommonPrefix(strs, split_pos, end_pos);
        int K = min(min_length, static_cast<int>(min(prefix_left.length(), prefix_right.length())));

        for (int i = 0; i < K; i++) {
            if (prefix_left[i] != prefix_right[i]) {
                return prefix_left.substr(0, i);
            }
        }

        return prefix_left.substr(0, K);
    }

private:
    int min_length = INT_MAX;
};
// LC Solution class goes here

int main() {
    Solution s;

    vector<string> input;
    string correct_result;
    string result;

    input = {"flower","flow","flight"};
    correct_result = "fl";
    result = s.longestCommonPrefix(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

    input = {"dog","racecar","car"};
    correct_result = "";
    result = s.longestCommonPrefix(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}