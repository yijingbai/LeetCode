#[UglyNumberIi](https://leetcode.com/problems/ugly-number-ii/)
######No: `264`
######Tag: `Math`
######Difficulty: `Medium`

This problem have several ways to solve. One of them is DP.

We set opt(n) means the nth ugly number. And the base case is that opt(1) = 1;
Then we know that opt(n) = min{opt[i] * 2, opt[j] * 3, opt[k] * 5}
where i, j, k is the number of 2, 3, 5.
Then after we got this, we need to update the i, j, k based on the minimum value.
