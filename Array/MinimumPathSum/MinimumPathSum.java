// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : Yijing Bai
// Date   : 2015-11-15

/**********************************************************************************
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to
 * bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 **********************************************************************************/


public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] cur = new int[m];
        cur[0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            cur[i] = cur[i - 1] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++) {
                cur[i] = Math.min(cur[i - 1], cur[i]) + grid[i][j];
            }
        }
        return cur[m - 1];

    }
}
