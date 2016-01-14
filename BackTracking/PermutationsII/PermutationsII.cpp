// Source : https://leetcode.com/problems/permutations-ii/
// Author : Yijing Bai
// Date   : 2016-01-13

/**********************************************************************************
 *
 * Given a collection of numbers that might contain duplicates, return all possible
 * unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 **********************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& res, int pos, vector<int> nums)//0...pos-1 already permutated
    {
        if(pos == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); ++i)
        {
            if(i != pos && nums[i] == nums[pos]) continue;
            swap(nums[i], nums[pos]);
            helper(res, pos + 1, nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())return res;
        sort(nums.begin(), nums.end());
        helper(res, 0, nums);
        return res;
    }
};


int main() {
	vector<int> input{1,1,2};
	Solution s;
	s.permuteUnique(input);
}
