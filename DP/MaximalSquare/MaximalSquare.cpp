// Source : https://leetcode.com/problems/maximal-square/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing
 * all 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 4.
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all test
 * cases.
 *
 *
 **********************************************************************************/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size(), width = height ? matrix[0].size() : 0;
        vector<vector<int>> size(height, vector<int>(width, 0));
        int max_size = 0;

        for (int i = 0; i < width; i++) {
            size[0][i] = matrix[0][i] - '0';
            max_size = max(max_size, size[0][i]);

        }

        for (int i = 0; i < height; i++) {
            size[i][0] = matrix[i][0] - '0';
            max_size = max(max_size, size[i][0]);
        }

        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                if (matrix[i][j] == '0') size[i][j] = 0;
                else {
                    size[i][j] = min(min(size[i-1][j], size[i][j-1]), size[i-1][j-1]) + 1;
                    max_size = max(max_size, size[i][j]);
                }
            }
        }

        return max_size * max_size;


    }
};

