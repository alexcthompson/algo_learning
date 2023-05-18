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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }

        long scale = 1;

        while (scale * 10 <= x) {
            scale *= 10;
        }

        int cur = x;
        int front = 10;
        int back = scale;

        while (front <= back) {
            int front_res = (cur % front) / (front / 10);
            int back_res = cur / back;

            if (front_res != back_res) {
                return false;
            }

            cur -= front_res / (front/10);
            front *= 10;
            cur -= back_res * back;
            back /= 10;
        }

        return true;
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    int input;
    bool correct_result;
    bool result;

    input = 121;
    correct_result = true;
    result = s.isPalindrome(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}