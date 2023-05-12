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
    int romanToInt(string s) {
        int res = 0;
        int pos = 0;
        int N = s.length();

        while (pos < N) {
            int cur_val = roman_int_map[s[pos]];

            if (pos < N - 1 && cur_val < roman_int_map[s[pos + 1]]) {
                res -= cur_val;
            } else {
                res += cur_val;
            }

            pos++;
        }

        return res;
    }

private:
    unordered_map<char, int> roman_int_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};
// LC Solution class goes here

int main() {
    Solution s;

    string input;
    int correct_result;
    int result;

    input = "III";
    correct_result = 3;
    result = s.romanToInt(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}