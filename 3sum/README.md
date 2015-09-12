#[3sum](https://leetcode.com/problems/3sum/)
######No: `15`
######Tag: `Array`
######Difficulty: `Medium`
This Problem is difficult for me at first. But using 2 pointer could solve this problem.

1. Sort the array.
2. Left k be the first element and i = k + 1, j = nums.size() -1. This definition is for
we get nums[k] + nums[i] + nums[j] and check whether it is zero.
3. Since the array is sorted, if nums[i] + nums[j] > -nums[k], means it's should be smaller,
so we should move the right pointer j to the left.
4. Else if the nums[i] + nums[j] < -nums[k], it should be bigger, so we move the left pointer
i right;
5. If the result is equal, we could add the nums[k], nums[i], nums[j] into the result array.
 
