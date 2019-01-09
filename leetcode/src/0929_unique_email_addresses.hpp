/*
Solution for LeetCode #929 'Unique Email Addresses'
https://leetcode.com/problems/unique-email-addresses/
Runtime: 48ms for 173 test cases, 8th percentile :( [need to reimplement!]
Time complexity: O(m * n) where m is the lenghth of the longest email address
and n is the number of email addresses.
*/

#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::string;


string parse_email(const string& email_in) {
    string res;

    bool ignore = false, domain = false;

    for (auto c : email_in) {
        if (domain) res += c;
        else if (c == '@') {
            domain = true;
            res += c;
        }
        else if (!ignore) {
            if (c == '+') ignore = true;
            else if (c != '.') res += c;
        }
    }

    return res;
}

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if (emails.size() <= 1) return emails.size();

        std::unordered_set<string> unique_emails;

        for (auto email : emails) unique_emails.insert(parse_email(email));

        return unique_emails.size();
    }
};