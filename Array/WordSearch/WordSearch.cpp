class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }
        int m = board.size(), n = board[0].size(), s_len = word.size();
        bool res = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(res = dfs(board, i, j, word, 0, m, n, s_len)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int start, int m, int n, int s_len) {
        bool res = false;
        char current_char = board[x][y];
        if (word[start] != current_char) {
            return false;
        }
        if (start == s_len - 1) {
            return true;
        }
        board[x][y] = '*';
        if (x > 0) res = dfs(board, x - 1, y, word, start + 1, m, n, s_len);
        if (!res && x < m - 1) res = dfs(board, x + 1, y, word, start + 1, m, n, s_len);
        if (!res && y < n - 1) res = dfs(board, x, y + 1, word, start + 1, m, n, s_len);
        if (!res && y > 0) res = dfs(board, x, y - 1, word, start + 1, m, n, s_len);
        board[x][y] = current_char;
        return res;
    }
};

