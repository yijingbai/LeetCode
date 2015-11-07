// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Yijing Bai
// Date   : 2015-10-13
/**********************************************************************************
 *
 * Find all possible combinations of k numbers that add up to a number n, given that
 * only numbers from 1 to 9 can be used and each combination should be a unique set of
 * numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 *
 *  Example 1:
 * Input:  k = 3,  n = 7
 * Output:
 *
 * [[1,2,4]]
 *
 *  Example 2:
 * Input:  k = 3,  n = 9
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 **********************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        return combination_sum3_helper(k, n, 1, result);
    }

    vector<vector<int> > combination_sum3_helper(int k, int target, int start, vector<vector<int> > result) {
        if (k == 0) return result;

        for (int i = start; i < 10; i++) {

            if (i < target) {
                for (vector<int> r : combination_sum3_helper(k - 1, target - i, i + 1, result)) {
                    r.insert(r.begin(), i);
                    result.push_back(r);
                }
            } else if (i == target) {
                vector<int> r;
                r.push_back(i);
                result.push_back(r);
                return combination_sum3_helper(k - 1, target - i, i + 1, result);
            } else {
                break;
            }
        }
        return result;
    }
};

int main () {
    Solution s;
    s.combinationSum3(3, 9);
}
