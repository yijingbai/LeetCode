// Source : https://leetcode.com/problems/trapping-rain-water/
// Author : Yijing Bai
// Date   : 2016-01-15

/**********************************************************************************
 *
 * Given n non-negative integers representing an elevation map where the width of each
 * bar is 1, compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this
 * case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for
 * contributing this image!
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int res = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] > max_left) max_left = height[left];
                else res += max_left - height[left];
                left++;
            } else {
                if (height[right] > max_right) max_right = height[right];
                else res += max_right - height[right];
                right--;
            }
        }
        return res;
    }
};

