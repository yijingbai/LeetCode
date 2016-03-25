// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author : Yijing Bai
// Date   : 2016-03-25

/**********************************************************************************
 *
 * You are given an integer array nums and you have to return a new counts array.
 * The counts array has the property where counts[i] is
 * the number of smaller elements to the right of nums[i].
 *
 * Example:
 *
 * Given nums = [5, 2, 6, 1]
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 * Return the array [2, 1, 1, 0].
 *
 **********************************************************************************/


class Solution {
private:
    void merge_count_smaller(vector<int>& indices, int first, int last,
                             vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_count_smaller(indices, first, mid, results, nums);
            merge_count_smaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) && (nums[indices[idx1]] <= nums[indices[idx2]]))) {
                    tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } else {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin() + first);
        }

    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_count_smaller(indices, 0, n, results, nums);
        return results;
    }
};
