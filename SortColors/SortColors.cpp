// Source : https://leetcode.com/problems/sort-colors/
// Author : Yijing Bai
// Date   : 2015-09-11
/**********************************************************************************
 *
 * Given an array with n objects colored red, white or blue, sort them so that objects
 * of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array
 * with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 *
 *
 *
 *
 *
 **********************************************************************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
    }
private:
    void quick_sort(vector<int>&nums, int left, int right) {
        int pivot = nums[left + (right - left) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;
            if (i <= j) {
                swap(nums[i++], nums[j--]);
            }
        }
        if (left < j) {
            quick_sort(nums, left, j);
        }
        if (i < right) {
            quick_sort(nums, i, right);
        }

    }
};

