#[JumpGameIi](https://leetcode.com/problems/jump-game-ii/)
######No: `45`
######Tag: `Array`
######Difficulty: `Hard`

This problems could have two way to solve. One is greedy, we for every position
just need to choose the one that could make it the farest one. Each time we need
to plus the step.

The other is BFS, just treat the current position as the current level and all the
index that could reach as the fringe.
