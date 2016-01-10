// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Given n pairs of parentheses, write a function to generate all combinations of
 * well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 **********************************************************************************/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        generate_helper(res, "", n, 0);
        return res;
    }

    void generate_helper(vector<string>& res, string val, int n, int m) {
        if (n == 0 && m == 0) {res.push_back(val); return;}

        if (m > 0) generate_helper(res, val + ')', n, m - 1);
        if (n > 0) generate_helper(res, val + '(', n - 1, m + 1);

    }
};
