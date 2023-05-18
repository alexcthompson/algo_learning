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
    bool isValid(string s) {
        stack<char> state;

        fr(paren, s) {
            switch (paren) {
                case '(':
                    state.push(')');
                    break;
                case '[':
                    state.push(']');
                    break;
                case '{':
                    state.push('}');
                    break;
                case ')':
                case ']':
                case '}':
                    if (state.empty() || state.top() != paren) {
                        return false;
                    } else {
                        state.pop();
                        break;
                    }
            }
        }

        return state.empty();        
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    string input;
    bool correct_result;
    bool result;

    input = "()[]{}";
    correct_result = true;
    result = s.isValid(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}