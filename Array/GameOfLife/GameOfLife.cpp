// Source : https://leetcode.com/problems/game-of-life/
// Author : Yijing Bai
// Date   : 2016-01-08

/**********************************************************************************
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life,
 * is a cellular automaton devised by the British mathematician John Horton Conway in
 * 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead
 * (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 * using the following four rules (taken from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by
 * reproduction.
 *
 * Write a function to compute the next state (after one update) of the board given its
 * current state.
 *
 * Follow up:
 *
 * Could you solve it in-place? Remember that the board needs to be updated at the same
 * time: You cannot update some cells first and then use their updated values to update
 * other cells.
 * In this question, we represent the board using a 2D array. In principle, the board
 * is infinite, which would cause problems when the active area encroaches the border
 * of the array. How would you address these problems?
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 *
 *
 **********************************************************************************/
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return;
        vector<vector<int>> new_board(board.size(), vector<int>(board[0].size(), 0));


        int n_count = 0;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i - 1 >= 0) {
                    n_count += board[i-1][j];
                    if (j - 1 >= 0) n_count += board[i-1][j-1];
                    if (j + 1 < board[0].size()) n_count += board[i-1][j+1];
                }
                if (j - 1 >= 0) n_count += board[i][j - 1];
                if (j + 1 < board[0].size()) n_count += board[i][j + 1];

                if (i + 1 < board.size()) {
                    n_count += board[i+1][j];
                    if (j - 1 >= 0) n_count += board[i+1][j-1];
                    if (j + 1 < board[0].size()) n_count +=board[i+1][j+1];
                }

                if (board[i][j]) {
                    if (n_count < 2) new_board[i][j] = 0;
                    else if (n_count == 2 || n_count == 3) new_board[i][j] = 1;
                    else if (n_count > 3) new_board[i][j] = 0;
                } else {
                    if (n_count == 3) new_board[i][j] = 1;
                }
                n_count = 0;

            }
        }

        swap(board, new_board);
    }
};

int main() {
    vector<vector<int>> input{{1, 1}};
    Solution s;
    s.gameOfLife(input);

}
