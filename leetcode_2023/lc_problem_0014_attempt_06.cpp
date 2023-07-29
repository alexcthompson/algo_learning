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
        if (strs.size() == 1) {
            return strs[0];
        }

        // find min length
        for (auto str : strs) {
            min_length = min(min_length, static_cast<int>(str.length()));
        }

        // binary search
        return longestCommonPrefix(strs, 0, strs.size());
    }

    string longestCommonPrefix(vector<string>& strs, start_pos, end_pos) {
        if (start_pos + 1 == end_pos) {
            return strs[start_pos];
        }

        int mid_pos = (start_pos + end_pos) / 2;
        string left_best = longestCommonPrefix(strs, start_pos, mid_pos);
        string right_best = longestCommonPrefix(strs, mid_pos, end_pos);
        int K = min(min_length, 
                    static_cast<int>(min(left_best.length(), right_best.length())));
        int match_len = 0;

        while (match_len < K) {
            if (left_best[match_len] != right_best[match_len]) {
                break;
            }

            match_len++;
        }
        
        min_length = min(min_length, match_len);

        return left_best.substr(0, match_len);
    }

private:
    int min_length = INT_MAX;
};
// LC Solution class goes here

int main() {
    Solution s;

    /*
    int input;
    int correct_result;
    int result;

    input = ;
    correct_result = ;
    result = ;

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
    */
}