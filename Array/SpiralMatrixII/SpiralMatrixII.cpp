// Source : https://leetcode.com/problems/spiral-matrix-ii/
// Author : Yijing Bai
// Date   : 2015-09-20

/**********************************************************************************
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in
 * spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if (n == 0) {
            return result;
        }
        for (int i = 0; i < n; i++) {
            vector<int> line;
            for (int j = 0; j < n; j++) {
                line.push_back(0);
            }
            result.push_back(line);
        }
        int i = 0, j = 0;
        int num = 1;
        int status = 0;
        while (i < n && j < n && result[i][j] == 0) {
            result[i][j] = num++;
            if (status == 0 && j < n) {
                if (j == n - 1 || result[i][j + 1] != 0) {
                    status = 1;
                    i++;
                    continue;
                }
                j++;
                continue;
            }
            if (status == 1 && i < n) {
                if (i == n - 1 || result[i + 1][j] != 0) {
                    status = 2;
                    j--;
                    continue;
                }
                i++;
                continue;
            }
            if (status == 2 && j >= 0) {
                if (j == 0 || result[i][j - 1] != 0) {
                    status = 3;
                    i--;
                    continue;
                }
                j--;
                continue;
            }
            if (status == 3 && i > 0) {
                if (i == 1 || result[i - 1][j] != 0) {
                    status = 0;
                    j++;
                    continue;
                }
                i--;
                continue;
            }
        }
    }
};

int main() {
    Solution s;
    s.generateMatrix(2);
}
