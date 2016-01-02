#[BinaryTreeZigzagLevelOrderTraversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
######No: `103`
######Tag: `Tree`
######Difficulty: `Medium`
This problem just need a little trick. First is the level order traversal of a binary tree. The idea is easy, when it reach
to the end of the line, we add a NULL pointer in the queue to indicate that here is the end of the line. To do this, we must
ensure that all the node in the current level are already added in the queue. Therefore, the sentence to add the null must shown
after the left and right child node has been added. Also, we need to judge that whether the queue is empty, if the queue is empty
we do not add the empty since it will cause the loop never stop.

The other trick is that when we want to traverse it zigzag, we do not need to force the traverse sequence is same as the result.
To make the order from right to the left, we just need to insert every node value from the beginning.
