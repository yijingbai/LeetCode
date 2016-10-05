// Source : https://leetcode.com/problems/water-and-jug-problem/
// Author : Yijing Bai
// Date   : 2016-10-04

/**********************************************************************************
 *
 * You are given two jugs with capacities x and y litres. There is an infinite amount
 * of water supply available.
 * You need to determine whether it is possible to measure exactly z litres using these
 * two jugs.
 *
 * If z liters of water is measurable, you must have z liters of water contained within
 * one or both buckets by the end.
 *
 * Operations allowed:
 *
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full or the
 * first jug itself is empty.
 *
 * Example 1: (From the famous "Die Hard" example)
 *
 * Input: x = 3, y = 5, z = 4
 * Output: True
 *
 * Example 2:
 *
 * Input: x = 2, y = 6, z = 5
 * Output: False
 *
 * Credits:Special thanks to @vinod23 for adding this problem and creating all test
 * cases.
 *
 **********************************************************************************/

class Solution {
public:
    int gcd(int m, int n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m%n);
    }

    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (z > x + y) return false;
        if (x == 0) return y == z;
        if (y == 0) return x == z;
        int g = gcd(x, y);
        return z % g == 0;
    }
};
