// Source : https://leetcode.com/problems/missing-number/
// Author : Yijing Bai
// Date   : 2015-11-15

/**********************************************************************************
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the
 * one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using
 * only constant extra space complexity?
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 *
 **********************************************************************************/

public class Solution {
    public int missingNumber(int[] nums) {
        int s = 0;
        for (int i = 1; i <= nums.length; i++) {
            s += i - nums[i - 1];
        }
        return s;
    }
}

