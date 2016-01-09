// Source : https://leetcode.com/problems/majority-element-ii/
// Author : Yijing Bai
// Date   : 2016-01-08

/**********************************************************************************
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋
 * times. The algorithm should run in linear time and in O(1) space.
 *
 *   How many majority elements could it possibly have?
 *   Do you have a better hint? Suggest it!
 *
 **********************************************************************************/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int a, b;

        for (int n : nums) {
            if (cnt1 == 0 || n == a) {
                cnt1++;
                a = n;
            } else if (cnt2 == 0 || n == b) {
                cnt2++;
                b = n;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;

        for (int n : nums) {
            if (n == a) cnt1++;
            else if (n == b) cnt2++;
        }

        vector<int> result;
        if (cnt1 > nums.size() / 3) result.push_back(a);
        if (cnt2 > nums.size() / 3) result.push_back(b);
        return result;

    }
};
