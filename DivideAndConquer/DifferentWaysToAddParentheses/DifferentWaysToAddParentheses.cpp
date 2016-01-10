// Source : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Given a string of numbers and operators, return all possible results from computing
 * all the different possible ways to group numbers and operators. The valid operators
 * are +, - and *.
 *
 * Example 1
 * Input: "2-1-1".
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 *
 * Example 2
 * Input: "2*3-4*5"
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10]
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 *
 **********************************************************************************/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;

        for (int i = 0; i < input.size(); ++i) {
            char c= input[i];
            if (c == '+' || c == '-' || c == '*') {
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    for (int b : diffWaysToCompute(input.substr(i + 1))) {
                        result.push_back(c == '+' ? a+b : c == '-' ? a-b : a * b);
                    }
                }
            }
        }
        if (result.size() == 0) return vector<int>{stoi(input)};
        else return result;
    }
};

