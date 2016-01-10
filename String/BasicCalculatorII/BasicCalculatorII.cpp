// Source : https://leetcode.com/problems/basic-calculator-ii/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, / operators and
 * empty spaces  . The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 *
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 *
 * Note: Do not use the eval built-in library function.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 **********************************************************************************/

class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') {
                total += term;
                in >> term;
                term *= op == '+' ? 1 : -1;
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
};
