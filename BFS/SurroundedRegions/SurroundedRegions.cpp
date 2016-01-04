// Source : https://leetcode.com/problems/surrounded-regions/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For eXample,
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 **********************************************************************************/
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        if (board.size() == 0) {
            return;
        }

        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                BFS(board, 0, i);
            }
            if (board[board.size() - 1][i] == 'O') {
                BFS(board, board.size() - 1, i);
            }

        }

        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                BFS(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                BFS(board, i, board[0].size() - 1);
            }

        }


        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void BFS(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> board_queue;
        board_queue.push(make_pair(x, y));
        while (!board_queue.empty()) {
            pair<int, int> coor = board_queue.front();
            board_queue.pop();

            if (board[coor.first][coor.second] == 'X' || board[coor.first][coor.second] == '#') continue;
            if (board[coor.first][coor.second] == 'O') board[coor.first][coor.second] = '#';

            if (coor.first - 1 >= 0) {
                board_queue.push(make_pair(coor.first - 1, coor.second));
            }
            if (coor.second + 1 < board[0].size()) {
                board_queue.push(make_pair(coor.first, coor.second + 1));
            }

            if (coor.first + 1 < board.size()) {
                board_queue.push(make_pair(coor.first + 1, coor.second));
            }

            if (coor.second - 1 >= 0) {
                board_queue.push(make_pair(coor.first, coor.second - 1));
            }

        }
    }
};

int main() {
	vector<char> l1{'X','X','X','X'};
	vector<char> l2{'X','O','O','X'};
	vector<char> l3{'X','X','O','X'};
	vector<char> l4{'X','O','X','X'};
	vector<vector<char> > board{l1, l2, l3, l4};
	Solution
}
