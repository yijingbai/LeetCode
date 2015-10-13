// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Yijing Bai
// Date   : 2015-10-13
/**********************************************************************************
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all unique
 * combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1
 * ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 *
 *
 *
 *
 *
 **********************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinatin_sum_helper(candidates, target, 0);
    }
    vector<vector<int>> combinatin_sum_helper(vector<int>& candidates, int target, int start) {
        vector<vector<int>> result;
        if (candidates.size() == 0) return result;
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) //remove duplicates.
                continue;
            if (candidates[i] < target) {
                for (vector<int> r : combinatin_sum_helper(candidates, target - candidates[i], i + 1)) {
                    r.insert(r.begin(), candidates[i]);
                    result.push_back(r);
                }
            } else if (candidates[i] == target) {
                vector<int> r;
                r.push_back(target);
                result.push_back(r);
            } else {
                break;
            }
        }
    }
};
