/*
Solution for LeetCode #13 Roman to Integer
https://leetcode.com/problems/roman-to-integer/
Runtime: 32 ms, 5th percentile
Time complexity: O(N)
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
        int pos = 0;
        int res = 0;

        while(pos < s.length()) {
            res += value(s, pos);
        }
        
        return res;
    }

private:
    unordered_map<string, int> values {
        {"I", 1},
        {"V",5},
        {"X",10},
        {"L",50},
        {"C",100},
        {"D",500},
        {"M",1000},
        {"IV",4},
        {"IX",9},
        {"XL",40},
        {"XC",90},
        {"CD",400},
        {"CM",900},
    };
    int value(string s, int& pos) {
        if (pos != s.length() - 1) {
            auto found = values.find(s.substr(pos, 2));

            if (found != values.end()) {
                pos += 2;
                return found->second;
            }
        }
        

        pos += 1;
        return values[s.substr(pos - 1, 1)];
    }
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
    input = "LVIII";
    correct_result = 58;
    result = s.romanToInt(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;

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