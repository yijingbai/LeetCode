// Source : https://leetcode.com/problems/next-permutation/
// Author : Yijing Bai
// Date   : 2015-10-15
/**********************************************************************************
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next
 * greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible
 * order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding
 * outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        sort(nums.begin(), nums.end());
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) {
            k--;
        }
        if (k - 1 > 0) {
            int l = nums.size() - 1;
            while (l >= 0 && nums[k - 1] >= nums[l]) l--;
            swap(nums[k - 1], nums[l]);
        }
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums {1, 2, 3};
    s.nextPermutation(nums);
}
