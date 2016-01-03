#[ConvertSortedListToBinarySearchTree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
######No: `108`
######Tag: `Tree`
######Difficulty: `Medium`
This problem is trivial. Since we want to construct a balanced binary search tree, so we should pick the median as
the root. Then we recursively pick the left root and right root and set them as the left child and the right child.
The problem is that when we find the median, we need to split the first half. 
First, I just want set the median to NULL. However, it does not work again. So I put the find median function into
the main function and add a prev to record the position before the median. Then we just set the `prev->next = NULL`
Then we done.
