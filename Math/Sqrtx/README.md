#[Sqrtx](https://leetcode.com/problems/sqrtx/)
######No: `69`
######Tag: `Math`
######Difficulty: `Medium`

There is at least two ways to solve this two problem.
The first is binary search.

For example, sqrt(2) = 1.414, we know that there must two numbers that are bigger than 1 and less than 2
that multiply to 2. Further, all the number in this range is sorted, so we can use binary search to find
it. we set mid = (left + right) / 2. And assume it is the answer. Then we just check whether it equal
to the x / mid. Since mid * mid = x. If mid < x / mid, means mid is so less, then we need to search
for the left part. Otherwise, we find in the left part.

The second approach is Newton's method. The explanation is from wikipidia:

![image](https://github.com/yijingbai/LeetCode/raw/master/Math/Sqrtx/wikipidia.png)
