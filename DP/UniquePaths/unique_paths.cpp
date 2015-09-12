#include <string>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mat[1000][1000];
        memset(mat, -1, sizeof(mat));
        return unique_path(0, 0, m, n, mat);
    }
private:
    int unique_path(int r, int c, int m, int n, int mat[][1000]) {
        if (r == m - 1 && c == n - 1) {
            return 1;
        }
        if (r >= m || c >= n) {
            return 0;
        }
        int down_path = 0, right_path = 0;
        if (mat[r + 1][c] != -1) {
            down_path = mat[r + 1][c];
        } else {
            down_path = unique_path(r + 1, c, m, n, mat);
            mat[r + 1][c] = down_path;
        }
        if (mat[r][c + 1] != -1) {
            right_path = mat[r][c + 1];
        } else {
            right_path = unique_path(r, c + 1, m, n, mat);
            mat[r][c + 1] = right_path;
        }
        int path_num = down_path + right_path;
        return path_num;
    }
};

int main() {
    Solution s;
    s.uniquePaths(1, 2);
    return 0;
}
