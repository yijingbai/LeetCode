// Source : https://leetcode.com/problems/combinations/
// Author : Yijing Bai
// Date   : 2016-01-13

/**********************************************************************************
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1
 * ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 *
 **********************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        if (n < k) return res;

        combine_helper(n, k, 1, res, cur);
        return res;
    }

    void combine_helper(int n, int k, int x, vector<vector<int>>& res, vector<int>& cur) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for (int i = x; i <= n; i++) {
            cur.push_back(i);
            combine_helper(n, k, i + 1, res, cur);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combine(10, 7);
}
