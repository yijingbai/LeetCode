#[ConstructBinaryTreeFromPreorderAndInorderTraversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
######No: `105`
######Tag: `Tree`
######Difficulty: `Medium`
We do not have idea initionally for this problem, but after thinking, from the preorder result, we can
know that the first element will always be the root node. Then we could found the target node in the
inorder array, and separate the node into two part. The left part is the left subtree and the right part
is the right subtree, then we can recursively build the tree for left and right.

There is another thing we need to consider. The memory. We just simply copy the node into a new vector.
However, the memory is run out of. So I change it to the pointer. We just need to use the index to represent
the target. This is much better since we only need O(1) memory.
