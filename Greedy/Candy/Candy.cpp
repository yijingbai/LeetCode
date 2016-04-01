// Source : https://leetcode.com/problems/candy/
// Author : Yijing Bai
// Date   : 2016-03-29

/**********************************************************************************
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 *
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size <= 1) return size;
        vector<int> num(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i-1]) {
                num[i] = num[i - 1] + 1;
            }
        }
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                num[i - 1] = max(num[i] + 1, num[i - 1]);
        }
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += num[i];
        }
        return result;
    }
};
