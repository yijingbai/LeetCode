// Source : https://leetcode.com/problems/create-maximum-number/
// Author : Yijing Bai
// Date   : 2016-02-05

/**********************************************************************************
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 *     Create the maximum number of length k  from digits of the two. The relative
 * order of the digits
 *     from the same array must be preserved. Return an array of the k digits. You
 * should try to optimize your time and space complexity.
 *
 *     Example 1:
 *
 *     nums1 = [3, 4, 6, 5]
 *     nums2 = [9, 1, 2, 5, 8, 3]
 *     k = 5
 *     return [9, 8, 6, 5, 3]
 *
 *     Example 2:
 *
 *     nums1 = [6, 7]
 *     nums2 = [6, 0, 4]
 *     k = 5
 *     return [6, 7, 6, 0, 4]
 *
 *     Example 3:
 *
 *     nums1 = [3, 9]
 *     nums2 = [8, 9]
 *     k = 3
 *     return [9, 8, 9]
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test
 * cases.
 *
 **********************************************************************************/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> best;
        for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1)
            best = max(best, maxNumber(maxNumber(nums1, k1),
                                       maxNumber(nums2, k-k1)));
        return best;
    }

    vector<int> maxNumber(vector<int> nums, int k) {
        int drop = nums.size() - k;
        vector<int> out;
        for (int num: nums) {
            while (drop && out.size() && out.back() < num) {
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
        vector<int> out;
        while (nums1.size() + nums2.size()) {
            vector<int>& now = nums1 > nums2 ? nums1 : nums2;
            out.push_back(now[0]);
            now.erase(now.begin());
        }
        return out;
    }
};


