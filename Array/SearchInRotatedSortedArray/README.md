#[SearchInRotatedSortedArray](https://leetcode.com/problems/search-in-rotated-sorted-array/)
######No: `33`
######Tag: `Array`
######Difficulty: `Medium`
This is a Binary Search Problem. But what is different from the ordinary binary search is that
not the total array is sorted since the array is rotated. The way to deal with this like the
the question before:

```
1) everytime check if targe == nums[mid], if so, we find it.
2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid]) 
  and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;
```
