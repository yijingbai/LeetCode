// Source : https://leetcode.com/problems/permutation-sequence/
// Author : Yijing Bai
// Date   : 2016-01-14

/**********************************************************************************
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 *
 **********************************************************************************/
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int group_num = 1;
        for (int i = n - 1; i >= 1; --i) {
            group_num *= i;
        }

        int s = ceil((double)k / group_num);
        int m = k % group_num;
        m == 0 ? m = group_num : 0;
        string result = to_string(s);

        for (int i = 1; i <= n; ++i) {
            if (i != s) {
                result += to_string(i);
            }
        }

        for (int i = 1; i < m; ++i) {
            next_permutation(result.begin(), result.end());
        }
        return result;
    }
};

int main() {
    Solution s;
    s.getPermutation(3, 2);
}
