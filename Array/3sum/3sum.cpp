// Source : https://leetcode.com/problems/3sum/
// Author : Yijing Bai
// Date   : 2015-09-11
/**********************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c
 * = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j = 0, k = 0, sum = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while (k < nums.size() && nums[k] <= 0) {
            i = k + 1;
            j = nums.size() - 1;

            while (i < j) {
                sum = nums[i] + nums[j];
                if (sum > -nums[k]) {
                    j--;
                    while (i < j && nums[j] == nums[j + 1]) j--;
                } else if (sum < -nums[k]) {
                    i++;
                    while (i < j && nums[i] == nums[i - 1]) i++;
                } else {
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    while (i < j && nums[i] == nums[i-1]) i++;
                    j--;
                    while (i < j && nums[j] == nums[j+1]) j--;
                }

            }
            k++;
            while (k < i && nums[k - 1] == nums[k]) k++;
        }
        return res;
    }
};
int main () {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(0);
    s.threeSum(nums);
}
