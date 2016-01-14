// Source : https://leetcode.com/problems/permutations/
// Author : Yijing Bai
// Date   : 2016-01-13

/**********************************************************************************
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 *
 **********************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;

        if (nums.size() == 1) {
            res.push_back(nums);
            return res;
        }

        int last = nums.back();
        nums.pop_back();

        vector<vector<int>> tmp_res = permute(nums);

        for (auto v : tmp_res) {
            for (int i = 0; i <= v.size(); i++) {

                auto pos = v.begin() + i;
                v.insert(pos, last);
                res.push_back(v);
                auto new_pos = v.begin() + i;
                v.erase(new_pos);
            }
        }

        return res;
    }

};

int main() {
	vector<int> input{1,2,3};
    Solution s;
    s.permute(input);
}
