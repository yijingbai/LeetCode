/ Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This
 * matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 *
 * Given target = 5, return true.
 * Given target = 20, return false.
 *
 *
 **********************************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size(), width = height == 0 ? 0 : matrix[0].size();

        if (height == 0) return false;

        int col = width - 1;
        int row = 0;

        while (col >= 0 && row < matrix.size()) {
            if (target == matrix[row][col]) return true;
            if (target > matrix[row][col]) {
                ++row;
                continue;
            } else if (target < matrix[row][col]) {
                --col;
                continue;
            }
        }

        return false;

    }
};

