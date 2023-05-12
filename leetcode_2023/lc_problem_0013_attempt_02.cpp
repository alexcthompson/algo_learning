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
        const int N = s.length();

        fo(pos, N) {
            int cur = roman_int_map[s[pos]];

            if (pos < N - 1 && cur < roman_int_map[s[pos + 1]]) {
                res -= cur;
            } else {
                res += cur;
            }
        }

        return res;
    }

private:
    unordered_map<char,int> roman_int_map = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
};
// LC Solution class goes here

int main() {
    Solution s;

    string input;
    int correct_result;
    int result;

    input = "MCMXCIV";
    correct_result = 1994;
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