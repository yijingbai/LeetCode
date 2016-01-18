// Source : https://leetcode.com/problems/longest-consecutive-sequence/
// Author : Yijing Bai
// Date   : 2016-01-17

/**********************************************************************************
 *
 * Given an unsorted array of integers, find the length of the longest consecutive
 * elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 **********************************************************************************/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for (int n : nums) {
            if (map[n]) continue;
            int left = map[n-1];
            int right = map[n+1];
            int sum = left + right + 1;
            map[n] = sum;
            res = max(res, sum);
            map[n-left] = sum;
            map[n+right] = sum;
        }
        return res;
    }
};

