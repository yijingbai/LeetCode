#[BinaryTreeInorderTraversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
######No: `94`
######Tag: `Tree`
######Difficulty: `Medium`
This is little different from the first order traversal. For this, we need to first push all the node in the left into
the stack and then for the right subtree, we also push all the left node in to the stack.
Compared to mine, the solution from the https://leetcode.com/discuss/19765/iterative-solution-in-java-simple-and-readable
is more consise:
```
public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> list = new ArrayList<Integer>();

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode cur = root;

    while(cur!=null || !stack.empty()){
        while(cur!=null){
            stack.add(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        list.add(cur.val);
        cur = cur.right;
    }

    return list;
}
```
