// Source : https://leetcode.com/problems/rotate-image/
// Author : Yijing Bai
// Date   : 2015-09-17
/**********************************************************************************
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 *
 **********************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = 0;
        if ((n = matrix.size()) == 0) {
            return;
        }
        int a = 0, b = n - 1, i = 0;
        while (a < b) {
            for (i = 0; i < (b - a); i++) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            a++;
            b--;
        }

    }
};
