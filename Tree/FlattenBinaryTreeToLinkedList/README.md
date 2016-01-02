#[FlattenBinaryTreeToLinkedList](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
######No: `114`
######Tag: `Tree`
######Difficulty: `Medium`
The idea for this problem is not hard, however, the implementation can be tricky, since we need to manipulate
the node inplace. The idea is to DFS the tree and make a new dummy head and add the root to the dummy head.
It is pretty easy, but we need to remember that the parameter is passed by value and if we want change it,
it self will not changed unless we changed the content it points to. So when we use recursion, and change the
dummy head, it will not changed. To fix this, we need to return the changed pointer in the end and use it as
the new dummy head. 

So If we face the problem like inplace manipulate, we'd better use iterative approach instead of the recursion
approach.

And there is an better approach from https://leetcode.com/discuss/30719/my-short-post-order-traversal-java-solution-for-share
, which is much better than mine:

```
private TreeNode prev = null;

public void flatten(TreeNode root) {
    if (root == null)
        return;
    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
}
```
