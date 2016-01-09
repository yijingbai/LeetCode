#[PowxN](https://leetcode.com/problems/powx-n/)
######No: `50`
######Tag: `Math`
######Difficulty: `Medium`

Initially, I thought it is a very easy question and just multiply the x for n times.
However, I failed to consider a lot of problems. First, the n could be 0 or negtive.
When n equal to 0, we should return 1. When n is negtive, what we need to do is totally
different.

Further, just loop n times will have performance issue. We could do this better by using
d&q technique. Since the left part of the problem and the right part of the problem is
totally the same. So we can solve this problem by solve its subproblem.

When doing divide and conquer, there are three cases:

1. WHen n even, no matter it is possitive or negative, we just multiply them. Since 2 * 2 =4   1/2 * 1/4 = 1/4
2. When n is odd, the case is more difficult. Since when n is positive and negtive is differernt. When n is positive,
we need to multiply the myPow(x, n / 2) * myPow(x, n / 2) * x, this is because when n is left, there will be one
x left. So we need to multiply it seperately. And when n is negative, we should ot multiply it. Instread, we should
divide it. Like (1/2 * 1/2)/2 
