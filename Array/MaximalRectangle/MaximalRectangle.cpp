// Source : https://leetcode.com/problems/maximal-rectangle/
// Author : Yijing Bai
// Date   : 2016-01-18

/**********************************************************************************
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing all ones and return its area.
 *
 **********************************************************************************/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> height(n, 0), left_boundary(n, 0), right_boundary(n, n);
        int result = 0;
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    left = j + 1;
                    height[j] = 0;
                    left_boundary[j] = 0;
                    right_boundary[j] = n;
                } else {
                    height[j]++;
                    left_boundary[j] = max(left_boundary[j], left);
                }
            }

            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    right = j;
                } else {
                    right_boundary[j] = min(right_boundary[j], right);
                    result = max(result, height[j] * (right_boundary[j] - left_boundary[j]));
                }
            }
        }
        return result;
    }
};

