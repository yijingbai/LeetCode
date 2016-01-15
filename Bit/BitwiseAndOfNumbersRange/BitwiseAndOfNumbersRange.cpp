// Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author : Yijing Bai
// Date   : 2016-01-15

/**********************************************************************************
 *
 * Given a range [m, n] where 0
 *
 * For example, given the range [5, 7], you should return 4.
 *
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};

