// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Author : Yijing Bai
// Date   : 2016-01-30

/**********************************************************************************
 *
 * Given a string containing just the characters '(' and ')', find the length of the
 * longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is
 * "()()", which has length = 4.
 *
 **********************************************************************************/


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxlength = 0;
        for (int i = 0; i < s.size(); ++i)  {
            int t = stk.top();
            if (t != -1 && s[i] == ')' && s[t] == '(') {
                stk.pop();
                maxlength = max(maxlength, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        return maxlength;
    }
};
