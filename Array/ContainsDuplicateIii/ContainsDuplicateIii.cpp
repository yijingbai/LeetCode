// Source : https://leetcode.com/problems/contains-duplicate-iii/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Given an array of integers, find out whether there are two distinct indices i and j
 * in the array such that the difference between nums[i] and nums[j] is at most t and
 * the difference between i and j is at most k.
 *
 **********************************************************************************/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]);
            // -t <= x-nums[i] <= t
            auto x = window.lower_bound(nums[i] - t);
            if (x != window.end() && *x - nums[i] <= t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
