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
    string best_prefix(const vector<string>& strs, int left, int right) {
        if (left + 1 == right) return strs[left];

        int c = (left + right) / 2;
        string left_str = best_prefix(strs, left, c);
        string right_str = best_prefix(strs, c, right);
        int K = min(left_str.length(), right_str.length());
        
        for (int i = 0; i < K; i++) {
            if (left_str[i] != right_str[i]) {
                return left_str.substr(0, i);
            }
        }

        return left_str.substr(0, K);
    }

    string longestCommonPrefix(vector<string>& strs) {
        return best_prefix(strs, 0, strs.size());
    }
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

    input = {"dog","racecar","car"};
    correct_result = "";
    result = s.longestCommonPrefix(input);

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}