// Source : https://leetcode.com/problems/shortest-palindrome/
// Author : Yijing Bai
// Date   : 2016-01-30

/**********************************************************************************
 *
 * Given a string S, you are allowed to convert it to a palindrome by adding characters
 * in front of it. Find and return the shortest palindrome you can find by performing
 * this transformation.
 *
 * For example:
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test
 * cases. Thanks to @Freezen for additional test cases.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = p[j - 1];
            }
            p[i] = (j += l[i] == l[j]);
        }
        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;

    }
};
