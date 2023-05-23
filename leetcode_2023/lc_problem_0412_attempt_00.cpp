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
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        fo(i, n) {
            if ((i + 1) % 3 == 0) {
                if ((i + 1) % 5 == 0) {
                    res.push_back("FizzBuzz");
                } else {
                    res.push_back("Fizz");
                }
            } else if ((i + 1) % 5 == 0) {
                res.push_back("Buzz");
            } else {
                res.push_back(to_string(i + 1));
            }
        }

        return res;
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    int input;
    vector<string> correct_result;
    vector<string> result;

    input = 3;
    correct_result = {"1","2","Fizz"};
    result = s.fizzBuzz(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

    input = 15;
    correct_result = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
    result = s.fizzBuzz(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}