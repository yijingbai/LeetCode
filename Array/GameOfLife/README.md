#[GameOfLife](https://leetcode.com/problems/game-of-life/)
######No: `289`
######Tag: `Array`
######Difficulty: `Medium`

The basic question is easy, but the follow up is more difficult.
For the basic one, we just need to simulate.

Cited from https://leetcode.com/discuss/61912/c-o-1-space-o-mn-time
There is a very nice implementation without using extra space:
```
Since the board has ints but only the 1-bit is used, I use the 2-bit to store the new state. At the end, replace the old state with the new state by shifting all values one bit to the right.

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;

            /*
            This loop solve both to add the count of 1 and also check the bound.
            Much better than write one by one.
            */
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}
Note that the above count counts the live ones among a cell's neighbors and the cell itself. Starting with int count = -board[i][j] counts only the live neighbors and allows the neat

if ((count | board[i][j]) == 3)
test. Thanks to aileenbai for showing that one in the comments.
```
