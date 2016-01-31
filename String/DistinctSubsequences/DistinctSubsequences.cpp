// Source : https://leetcode.com/problems/distinct-subsequences/
// Author : Yijing Bai
// Date   : 2016-01-30

/**********************************************************************************
 *
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string
 * by deleting some (can be none) of the characters without disturbing the relative
 * positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while
 * "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 *
 **********************************************************************************/


class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.length();
        int n = S.length();
        if (m > n) return 0;
        vector<vector<int>> path(m+1, vector<int>(n+1, 0));
        for (int k = 0; k <= n; k++) path[0][k] = 1;

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                path[i][j] = path[i][j-1] + (T[i-1] == S[j-1] ? path[i-1][j-1] : 0);
            }
        }
        return path[m][n];
    }
};
