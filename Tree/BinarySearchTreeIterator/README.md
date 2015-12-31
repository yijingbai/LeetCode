#[BinarySearchTreeIterator](https://leetcode.com/problems/binary-search-tree-iterator/)
######No: `173`
######Tag: `Tree`
######Difficulty: `Medium`
This is a typical binary search tree traversal problems. The diffence is that we need to do it step by step when the next was called.
We can use a stack to do this.
When initializing, we can put the left most branch into the stack.
Every time, when next is called, we pop one element, since it is the left most one, it will be the smallest.
Then we node the middle node will be the second least one. And it is already in the stack. So we only need to
push all the left nodes of the right node into the stack.
