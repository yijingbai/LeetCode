#[JumpGame](https://leetcode.com/problems/jump-game/)
######No: `55`
######Tag: `Array Greedy`
######Difficulty: `Medium`
I did not solve this problem by myself. Cited from https://leetcode.com/discuss/15567/linear-and-simple-solution-in-c
we can solve this by iterate and update the maximal index that I can reach.
```
bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}
```

For the i + A[i] is jump through one of the reached element. And reach is direct jump to the reached element.
we keep choose the max element then at last, if it could come to the n, return true, otherwise, return false.
