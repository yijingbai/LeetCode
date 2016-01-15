// Source : https://leetcode.com/problems/remove-duplicate-letters/
// Author : Yijing Bai
// Date   : 2016-01-14

/**********************************************************************************
 *
 * Given a string which contains only lowercase letters, remove duplicate letters so
 * that every letter appear once and only once. You must make sure your result is the
 * smallest in lexicographical order among all possible results.
 *
 * Example:
 *
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        int ahead[256] = {};
        for (char c : s) {
            ahead[c]++;
        }

        string result = " ";
        bool inresult[256] = {};

        for (char c : s) {
            ahead[c]--;
            if (inresult[c]) continue;
            while (c < result.back() && ahead[result.back()]) {
                inresult[result.back()] = false;
                result.pop_back();
            }
            result += c;
            inresult[c] = true;
        }

        return result.substr(1);
    }
};

