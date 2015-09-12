## MinimumSizeSubarraySum
For this question, I do not come up with the solution at first.
In the [disscution](https://leetcode.com/discuss/54765/290-ms-super-simple-java-solution), I found a easy solution.
It is use two pointer. The Algorithm is described as belows:

1. Define two pointers *LEFT* and *RIGHT* and a sum = 0.
2. If sum + nums[RIGHT] < target, we keep increasing the RIGHT pointer, and add sum.
3. If the expression >= target, we increasing the LEFT pointer, and since the LEFT pointer changed, we have to minus the
left most value. Then, we min(target, RIGHT - LEFT - 1).
4. After the loop finished, if the target != INT__MAX, target will be the result we want.

