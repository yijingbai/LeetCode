#[SingleNumberIii](https://leetcode.com/problems/single-number-iii/)
######No: `260`
######Tag: `BitManipulation`
######Difficulty: `Medium`
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num : nums) {
            diff ^= num;
        }

        diff &= -diff;

        vector<int> ret(2, 0);
        for (int num : nums) {
            ret[!(num & diff)] ^= num;
        }
        return ret;

    }
};

