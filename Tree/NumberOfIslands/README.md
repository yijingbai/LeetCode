#[NumberOfIslands](https://leetcode.com/problems/number-of-islands/)
######No: `200`
######Tag: `DFS BFS`
######Difficulty: `Medium`
This is a typical DFS or BFS problem. Both BFS and DFS could solve this problem.
The idea is that for each entry of the input, if it is 1, we start from it and do DFS or BFS.
For all the entry that are visited, we set it to another char, like 'x' and we do not visit them
again. And we traverse each entry that the value is 1. Each time increase the count. Then we done.
