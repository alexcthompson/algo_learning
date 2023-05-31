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
    int countOdds(int low, int high) {
        int len = high + 1 - low;

        return (len + (low % 2)) / 2;
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    int low; int high;
    int correct_result;
    int result;

    low = 8; high = 10;
    correct_result = 1;
    result = s.countOdds(low, high);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "low = " << low << "; high = " << high
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}