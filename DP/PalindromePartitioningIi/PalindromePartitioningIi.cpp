// Source : https://leetcode.com/problems/palindrome-partitioning-ii/
// Author : Yijing Bai
// Date   : 2016-03-27

/**********************************************************************************
 *
 * Given a string s, partition s such that every substring of the partition is a
 * palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
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
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);
        for (int i = 0; i <= n; i++) cut[i] = i - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 &&
                 i + j < n &&
                 s[i - j] == s[i + j]; j++)
                 cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j]);
            for (int j = 1; i-j+1 >= 0 && i + j < n
                 && s[i - j + 1] == s[i + j]; j++)
                 cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j+1]);
        }
        return cut[n];
    }
};
