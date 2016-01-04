#[PerfectSquares](https://leetcode.com/problems/perfect-squares/)
######No: `279`
######Tag: `DP`
######Difficulty: `Medium`
This is a problem that could be solve by DP, math, BFS. For me, the DP is the easiest to understand.
for a given n, we define that OPT[n] is the least number of perfect squares that sum to n. Then we
now that:

for all the perfect square j * j that smaller than n, our equation could be:

OPT[n] = min{OPT[n], OPT[n - j * j] + 1}

The explanation for this equation is that we traverse all the square numbers, and if we use it to
sum to n, then there will be one more number.
