#[WaterAndJugProblem](https://leetcode.com/problems/water-and-jug-problem/)
######No: `365`
######Tag: `Microsoft`
######Difficulty: `Medium`

This is a math problem. The key is to proof that 
every z = ax - by in range[0, x + y] can be measured.
Thus we need to check z % gcd(x, y) == 0.

In addition, we need to check some corner cases:
1. z equals to zero, which means we don't need to measure, return true.
2. x == 0 or y == 0 means we could only use one container. Just return x or y == z
