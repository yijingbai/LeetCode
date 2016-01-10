#[CoinChange](https://leetcode.com/problems/coin-change/)
######No: `322`
######Tag: `DP`
######Difficulty: `Medium`

This is a typical and easy DP problem.
The equation is
```
OPT[i] means the fewest number of coins to make up the amount i.

OPT[i] = min{
For all the coin value c in coins
OPT[i], OPT[i - c] + 1
}

```
