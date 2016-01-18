#[\*FindTheDuplicateNumber](https://leetcode.com/problems/find-the-duplicate-number/)
######No: `287`
######Tag: `Array`
######Difficulty: `Hard`

This problem has two solutions. The first solution is that using two pointers. Slow pointer and
Fast pointer. Just exactly like what the LinkedList Cycle will do, we treating the number in the
array as the index, and moving the pointer. If there is a duplicant, there must be a loop.
Then the rest will like the LinkedList Cycle.
Cited from https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
there is a very nice explanation:
```
The main idea is the same with problem Linked List Cycle II,
https://leetcode.com/problems/linked-list-cycle-ii/. Use two 
pointers the fast and the slow. The fast one goes forward two
 steps each time, while the slow one goes only step each time. 
They must meet the same item when slow==fast. In fact, they
 meet in a circle, the duplicate number must be the entry point
 of the circle when visiting the array from nums[0]. Next we 
just need to find the entry point. We use a point(we can use
 the fast one before) to visit form begining with one step each 
time, do the same job to slow. When fast==slow, they meet at the 
entry point of the circle. The easy understood code is as follows.
```

The second solution is binary search.
Cited from
```
This solution is based on binary search.

At first the search space is numbers between 1 to n. Each time I 
select a number mid (which is the one in the middle) and count all
 the numbers equal to or less than mid. Then if the count is more 
than mid, the search space will be [1 mid] otherwise [mid+1 n]. I
 do this until search space is only one number.

Let's say n=10 and I select mid=5. Then I count all the numbers in
 the array which are less than equal mid. If the there are more than 
5 numbers that are less than 5, then by Pigeonhole Principle 
(https://en.wikipedia.org/wiki/Pigeonhole_principle) one of them has 
occurred more than once. So I shrink the search space from [1 10] to
 [1 5]. Otherwise the duplicate number is in the second half so for
 the next step the search space would be [6 10].

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 1
        high = len(nums)-1

        while low < high:
            mid = low+(high-low)/2
            count = 0
            for i in nums:
                if i <= mid:
                    count+=1
            if count <= mid:
                low = mid+1
            else:
                high = mid
        return low
There's also a better algorithm with O(n) time. Please read this very 
interesting solution here: http://keithschwarz.com/interesting/code/?dir=find-duplicate
```
