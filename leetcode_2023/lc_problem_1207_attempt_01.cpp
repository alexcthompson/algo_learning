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
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> num_counts;

        fr(num, arr) {
            num_counts[num] += 1;
        }

        unordered_set<int> count_counts;

        fr(num_count_kv, num_counts) {
            int num_count = num_count_kv.second;

            if (count_counts.count(num_count) != 0) {
                return false;
            } else {
                count_counts.insert(num_count);
            }
        }

        return true;
    }
};
// LC Solution class goes here

int main() {
    Solution s;

    vi input;
    bool correct_result;
    bool result;

    input = {1,2,2,1,1,3};
    correct_result = true;
    result = s.uniqueOccurrences(input);

    if (result == correct_result) {
        cout << "success:" << endl;
    } else {
        cout << "**FAILURE**:" << endl;
    }

    cout << "input = " << input
         << ";\ncorrect_result = " << correct_result <<
         ";\nresult = " << result << endl << endl;
}