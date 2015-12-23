// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Author : Yijing Bai
// Date   : 2015-12-22

/**********************************************************************************
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the
 * tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is
 * defined between two nodes v and w as the lowest node in T that has both v and w as
 * descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example
 * is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according
 * to the LCA definition.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;

        if (root == NULL) {
            return NULL;
        }

        get_path(root, p, path_p);
        get_path(root, q, path_q);

        TreeNode* result = NULL;
        for (int i = 0, j = 0; i < path_p.size() && j < path_q.size(); i++, j++) {
            if (path_p[i] == path_q[j]) {
                result = path_p[i];
                continue;
            } else {
                break;
            }
        }
        return result;
    }

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
};


