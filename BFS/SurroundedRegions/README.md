#[SurroundedRegions](https://leetcode.com/problems/surrounded-regions/)
######No: `130`
######Tag: `BFS`
######Difficulty: `Medium`
Actually this problem could be solve using both DFS and BFS. Since last time, we use DFS, this time,
we use BFS.
Initionally, I go into a run path that using BFS to traverse every node in the board, which cause the
Time exceeded.

However, we could simply do BFS for the border `O`, since the border `O` must not surrended by `X`. And we
mark visited `O` to `#`, then we just need to flip the `#` to the `O`, since they are not surrended, and 
flip `O` to the `X` since they are surrended.
