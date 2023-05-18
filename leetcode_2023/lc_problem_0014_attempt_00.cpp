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
        switch (strs.size()) {
            case 1:
                return strs[0];
            case 2:
                break;
            default:
                std::sort(strs.begin(), strs.end());
                break;
        }
        
        // check first and last, return common prefix
        string stra = strs.front();
        string strb = strs.back();
        int N = min(stra.length(), strb.length());
        string res = "";

        fo(i, N) {
            if (stra[i] != strb[i]) {
                break;
            } else {
                res.push_back(stra[i]);
            }
        }

        return res;
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