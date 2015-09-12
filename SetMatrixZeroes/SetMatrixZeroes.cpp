// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Yijing Bai
// Date   : 2015-09-12
/**********************************************************************************
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it
 * in place.
 *
 * click to show follow up.
 *
 * Follow up:
 *
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 *
 **********************************************************************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (0 == matrix.size()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> zero_vector;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero_vector.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < zero_vector.size(); i++) {
            set_row_line_zero(matrix, m, n, zero_vector[i][0], zero_vector[i][1]);
        }

    }
private:
    void set_row_line_zero(vector<vector<int>>& matrix, int m, int n, int x, int y) {
        for (int i = 0; i < n; i++) {
            matrix[x][i] = 0;
        }
        for (int j = 0; j < m; j++) {
            matrix[j][y] = 0;
        }
    }
};
