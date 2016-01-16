#[FirstMissingPositive](https://leetcode.com/problems/first-missing-positive/)
######No: `41`
######Tag: `Array`
######Difficulty: `Medium`

Cited from https://leetcode.com/discuss/24013/my-short-c-solution-o-1-space-and-o-n-time
```
Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.
```

About how to put each number in its right place also need to carelly write the code.
The idea is that we the current position's element is not equal to what it should be, swap it
with the position where it should be. When keep doing this, finally, all the numbers should in
its right place
