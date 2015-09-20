// Source : https://leetcode.com/problems/subsets/
// Author : Yijing Bai
// Date   : 2015-09-20

/**********************************************************************************
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note:
 *
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 *
 **********************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() <= 0) {
            result.push_back(nums);
            return result;
        }

        sort(nums.begin(), nums.end());

        int last = nums[nums.size() - 1];
        nums.erase(nums.end() - 1);

        for(vector<int> e : subsets(nums)) {
            result.push_back(e);
            e.push_back(last);
            result.push_back(e);
        }
        return result;

    }
};


