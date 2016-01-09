// Source : https://leetcode.com/problems/power-of-three/
// Author : Yijing Bai
// Date   : 2016-01-08

/**********************************************************************************
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 *     Follow up:
 *     Could you do it without using any loop / recursion?
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test
 * cases.

 *
 *
 **********************************************************************************/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)));
    }
};

