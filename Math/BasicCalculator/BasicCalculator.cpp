// Source : https://leetcode.com/problems/basic-calculator/
// Author : Yijing Bai
// Date   : 2016-01-09

/**********************************************************************************
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus + or
 * minus sign -, non-negative integers and empty spaces  .
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 *
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 *
 * Note: Do not use the eval built-in library function.
 *
 **********************************************************************************/


class Solution {
public:
    int calculate(string s) {
        stack<int> sign_s;
        int res = 0;
        int stack_v;
        int num =0;
        int sign = 1;

        sign_s.push(1);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                res += sign_s.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                sign_s.push(sign * sign_s.top());
                sign = 1;
            } else if (c == ')') {
                res += sign_s.top() * sign * num;
                num = 0;
                sign_s.pop();
                sign = 1;
            }
        }

        if (num) {
            res += sign_s.top() * sign * num;
        }

        return res;


    }
};
