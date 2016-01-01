#[BinaryTreeRightSideView](https://leetcode.com/problems/binary-tree-right-side-view/)
######No: `199`
######Tag: `Tree`
######Difficulty: `Medium`
Quoting from #[here](https://leetcode.com/discuss/31348/my-simple-accepted-solution-java), the key idea is:
1. Each depth of the tree only select one node.
2. View depth is current size of result list.
Therefore, we can add a judgement that when current depth equals to the size of the result, we can add the current
node into the result. Otherwise, if the current depth is smaller than the size of the result, which means there is
already a node in the result, we just recursive find the next level of the tree. To do this, we just need to recursive
call on the right node and the left node. Noticing that the right node is called first.
