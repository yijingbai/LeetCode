class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int index = binary_search_row(matrix, target, m, n);
        if (index == -1) {
            return false;
        }
        return binary_search_col(matrix[index], target, n);
    }
private:
    int binary_search_row(vector<vector<int>>& matrix, int target, int m, int n) {
        int i = 0, j = m, mid = 0;
        while (i <= j) {
            mid = (i + j) / 2;
            if (matrix[mid][0] <= target && matrix[mid][n] >= target) {
                return mid;
            } else if (matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }

    bool binary_search_col(vector<int> & line, int target, int n) {
        int i = 0, j = n, mid = 0;
        while (i <= j) {
            mid = (i + j) / 2;
            if (line[mid] == target) {
                return true;
            } else if (line[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return false;
    }
};
