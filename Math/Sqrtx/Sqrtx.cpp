// Source : https://leetcode.com/problems/sqrtx/
// Author : Yijing Bai
// Date   : 2016-01-09

/**********************************************************************************
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 *
 *
 **********************************************************************************/

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};


