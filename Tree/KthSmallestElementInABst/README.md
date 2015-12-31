#[KthSmallestElementInABst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
######No: `230`
######Tag: `Tree`
######Difficulty: `Medium`
We can solve this using binary search with the property of the Binary Search Tree.
Since we need to find the kth smallest, we need to count the number of nodes. It can be done
easily using a recursion. Then given a root node, we know all the node in the left side of the
node is less than the root. We just need to count the number of node at the left side. Then judge 
whether the count number is smaller or bigger than the k. If k smaller than the count, we know the
kth smallest element will be in the left side. Otherwise, it will be the root or the right side.
Remember that the root itself also count the node.
