// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Yijing Bai
// Date   : 2016-01-08

/**********************************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index,
 * otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 *
 **********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> input{3, 1};
    Solution s;
    s.search(input, 1);
}
