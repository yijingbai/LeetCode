// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : Yijing Bai
// Date   : 2015-09-11
/**********************************************************************************
 *
 * Given an array of n positive integers and a positive integer s, find the minimal
 * length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * click to show more practice.
 *
 * More practice:
 *
 * If you have figured out the O(n) solution, try coding another solution of which the
 * time complexity is O(n log n).
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 **********************************************************************************/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, target = INT_MAX, sum = 0;
        while (right < nums.size()) {
            if (sum + nums[right] < s) {
                sum += nums[right];
                right++;
            } else {
                target = min(target, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return INT_MAX == target ? 0 : target;
    }
};
