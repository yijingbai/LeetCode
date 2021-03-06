// Source : https://leetcode.com/problems/single-number-ii/
// Author : Yijing Bai
// Date   : 2016-01-15

/**********************************************************************************
 *
 * Given an array of integers, every element appears three times except for one. Find
 * that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it
 * without using extra memory?
 *
 *
 **********************************************************************************/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

