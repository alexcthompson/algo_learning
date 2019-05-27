/*
Solution for LeetCode #273 'Integer to English Words'
https://leetcode.com/problems/integer-to-english-words/
Runtime: X ms for Y test cases, Zth percentile (no further differentiation)
Time complexity:
*/

#include <string>

class Solution {
public:
    std::string numberToWords(int num) {
        if (num <= 19) {
            switch(num) {
                case 0: return "Zero";
                case 1: return "One";
                case 2: return "Two";
                case 3: return "Three";
                case 4: return "Four";
                case 5: return "Five";
                case 6: return "Six";
                case 7: return "Seven";
                case 8: return "Eight";
                case 9: return "Nine";
                case 10: return "Ten";
                case 11: return "Eleven";
                case 12: return "Twelve";
                case 13: return "Thirteen";
                case 14: return "Fourteen";
                case 15: return "Fifteen";
                case 16: return "Sixteen";
                case 17: return "Seventeen";
                case 18: return "Eighteen";
                case 19: return "Nineteen";
            }
        }
        else if (num < 100 && num % 10 == 0) {
            switch(num) {
                case 20: return "Twenty";
                case 30: return "Thirty";
                case 40: return "Forty";
                case 50: return "Fifty";
                case 60: return "Sixty";
                case 70: return "Seventy";
                case 80: return "Eighty";
                case 90: return "Ninety";
            }
        }
        else if (num < 100) {
            return numberToWords((num / 10) * 10) + " " + numberToWords(num % 10);
        }
        else if (num < 1000 && num % 100 == 0) {
            return numberToWords(num / 100) + " Hundred";
        }
        else if (num < 1000) {
            return numberToWords((num / 100) * 100) + " " + numberToWords(num % 100);
        }
        else if (num < 1000000 && num % 1000 == 0) {
            return numberToWords(num / 1000) + " Thousand";
        }
        else if (num < 1000000) {
            return numberToWords((num / 1000) * 1000) + " " + numberToWords(num % 1000);
        }
        else if (num < 1000000000 && num % 1000000 == 0) {
            return numberToWords(num / 1000000) + " Million";
        }
        else if (num < 1000000000) {
            return numberToWords((num / 1000000) * 1000000) + " " + numberToWords(num % 1000000);
        }
        else if (num >= 1000000000 && num % 1000000000 == 0) {
            return numberToWords(num / 1000000000) + " Billion";
        }
        else if (num >= 1000000000) {
            return numberToWords((num / 1000000000) * 1000000000) + " " + numberToWords(num % 1000000000);
        }

        return "NULL";
    }
};