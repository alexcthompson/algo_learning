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
        auto [min_str_ptr, max_str_ptr] = minmax_element(strs.begin(), strs.end());

        string min_str = *min_str_ptr; string max_str = *max_str_ptr;
        int N = min(min_str.length(), max_str.length());
        int pos = 0;

        while (pos < N && min_str[pos] == max_str[pos]) pos++;

        return min_str.substr(0, pos);
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