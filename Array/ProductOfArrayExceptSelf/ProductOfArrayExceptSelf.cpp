// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : Yijing Bai
// Date   : 2015-09-20

/**********************************************************************************
 *
 * Given an array of n integers where n > 1, nums, return an array output such that
 * output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not
 * count as extra space for the purpose of space complexity analysis.)
 *
 *
 *
 *
 **********************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product, right_product, result_array;
        int result = 1, n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) {
                result *= nums[i + 1];
            }
            right_product.push_back(result);
        }
        result = 1;
        for (int i = 0; i < n; i++) {
             if (i - 1 >= 0) {
                 result *= nums[i - 1];
             }
             result_array.push_back(result * right_product[n - i - 1]);
        }
        return result_array;
    }
};
