/*
Lilah's repeated string, HackerRank problem found here:
https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include <algorithm>
#include <string>

using std::string;

long count_letters(string s, char c) {
    return std::count(s.cbegin(), s.cend(), c);
}

long repeatedString(string s, long n) {
    long res = 0;
    long a_count = count_letters(s, 'a');
    string remaining_string = s.substr(0, n % s.length());
    int remaining_string_a_count = count_letters(remaining_string, 'a');

    return a_count * (n / s.length()) + remaining_string_a_count;
}