#[FindPeakElement](https://leetcode.com/problems/find-peak-element/)
######No: `162`
######Tag: `Array BinarySearch`
######Difficulty: `Medium`
We can solve this problem using binary search. Binary search could not only been used in the sorted array but
also used in an unsorted array. In this problem, we could use binary search to find a local peak.
After we get the element of the middle, we just need to compare the num[mid] and num[mid + 1].
The problem is that using this method could only find a local peak instead of the global peak.
