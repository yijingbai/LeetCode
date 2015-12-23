#[LowestCommonAncestorOfABinaryTree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
######No: `236`
######Tag: `Tree`
######Difficulty: `Medium`

LCA is a problem that could be difficult. However, for this problem, we just need to use the most naive solution.
First, we need to store the path from the root node to the target node. So we need a helper funtion to do this.
This funtion is easy, but easy to be wrong.

```cpp
    bool get_path(TreeNode* root, TreeNode* n, vector<TreeNode*>& path) {
        if (root == NULL) {
            return true;
        }

        path.push_back(root);
        if (root == n) {
            return true;
        }
        if (root->right != NULL) {
            if(get_path(root->right, n, path)) return true;
        }
        if (root->left != NULL) {
            if(get_path(root->left, n, path)) return true;
        }

        path.pop_back();
        return false;
    }
```
Initially, the function do not have a return value, which cause OOM. The reason is that after find the path, the funtion will
keep recursively traverse all the node with out stop. Only the base case returned and two recursion call not returned.
To fix this bug, we add a bool to indicate whether we already found a path. If so, directly return the path. The reason
why we store the path in the parameter is that if we keep the variable in the function, every time, we need to merge the value
with the vector hold by itself. To avoid this, we put the path in parameter, such that the global path is only one.

We could improve this by find the two path in the single traverse.
