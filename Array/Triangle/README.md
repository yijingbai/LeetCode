###### (Triangle)[https://leetcode.com/problems/triangle/]
###### Tag: `Array, DP`
###### Difficulty: `Medium`
It is a typical dp question. However, I do not come up at first time.
After studying many dp material, I understand it as well as the bottom
up dp soltion of this question. So we define the d[i][j] as the min value
of the path, then we can get the formula that `d[i][j] += min(d[i + 1][j], d[i + 1][j + 1])`

