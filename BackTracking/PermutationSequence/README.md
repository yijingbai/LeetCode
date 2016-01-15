#[PermutationSequence](https://leetcode.com/problems/permutation-sequence/)
######No: `60`
######Tag: `Backtracking Math`
######Difficulty: `Medium`
This is a math problem. The problem is that the number of permutations is a lot.
If we just traverse every possibile permutation, it is not possible. But Actually
we do not need to do this. for n = 3, all possible permutations are:
```
123
132
---
213
231
---
312
321
---
```
Clearly, we could see that for each number from 1 to n, there will be (n-1)! permutatons.
For given k, we just divide it by (n-1)!, then we know which group it belongs to. Then
we calculate k % (n-1)!, we know which permutation is k's. Then we could get the answer.

Note:
When k % (n-1)! == 0, actually it is the last element of the group, not 0, so we need to assign
k / (n-1)! to it.
