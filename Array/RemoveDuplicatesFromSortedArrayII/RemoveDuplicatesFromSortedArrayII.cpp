// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Yijing Bai
// Date   : 2015-09-20

/**********************************************************************************
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums being
 * 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 *
 *
 **********************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0, result = 0;
        for (int i = 0, j = 0; i < nums.size() && j < nums.size();) {
            if (nums[i] == nums[j]) {
                counter++;
                if (counter <  3) {
                    result++;
                } else {
                    nums.erase(nums.begin() + j);
                    continue;
                }
                j++;

            } else {
                i = j;
                counter = 0;
            }
        }
        return result;
    }
};
