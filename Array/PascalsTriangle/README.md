## Pascal's Triangle
This problem is quite easy. Finding the pascal's triangle rule is enough.

1. The two side of each subarray should be 1.
2. In the middle of the array, a[j] = res[i - 1][j - 1] + res[i - 1][j].
