// Source : https://leetcode.com/problems/jump-game-ii/
// Author : Yijing Bai
// Date   : 2016-01-17

/**********************************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first
 * index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0
 * to 1, then 3 steps to the last index.)
 *
 * Note:
 * You can assume that you can always reach the last index.
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cur = 0, max_p = 0, steps = 0, next = 0;
        while (cur < nums.size() - 1) {
            if (cur + nums[cur] >= nums.size() - 1) {++steps; break;}
            for (int i = cur; i < nums.size() && i <= cur + nums[cur]; i++) {
                if (i + nums[i] > max_p) {
                    next = i;
                    max_p = i + nums[i];
                }
            }
            ++steps;
            cur = next;
        }
        return steps;
    }
};


int main() {
    Solution s;
    vector<int> input{1, 2, 3};
    s.jump(input);
}
