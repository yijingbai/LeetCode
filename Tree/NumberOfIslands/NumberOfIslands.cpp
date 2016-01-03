// Source : https://leetcode.com/problems/number-of-islands/
// Author : Yijing Bai
// Date   : 2016-01-03

/**********************************************************************************
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An
 * island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 *
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 *
 *
 **********************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    numIslandsHelper(grid, i, j);
                    ++num;
                }
            }
        }
        return num;
    }

    void numIslandsHelper(vector<vector<char> >& grid,
        int x, int y) {
        if (grid[x][y] == '0' || grid[x][y] == 'x') {
            return;
        }
        grid[x][y] = 'x';
        if (x - 1 >= 0) {
            numIslandsHelper(grid, x - 1, y);
        }
        if (y + 1 < grid[0].size()) {
            numIslandsHelper(grid, x, y + 1);
        }
        if (x + 1 < grid.size()) {
            numIslandsHelper(grid, x + 1, y);
        }
        if (y - 1 >= 0) {
            numIslandsHelper(grid, x, y - 1);
        }
    }
};

int main() {
	Solution s;
	vector<char> in;
	in.push_back('1');
	in.push_back('1');
	vector<vector<char> > input;
	input.push_back(in);

	s.numIslands(input);
}
