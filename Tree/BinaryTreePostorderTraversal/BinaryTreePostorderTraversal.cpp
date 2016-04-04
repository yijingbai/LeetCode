// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Yijing Bai
// Date   : 2016-04-04

/**********************************************************************************
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [3,2,1].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;

        if (root == NULL) return result;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            result.push_back(node->val);
            nodeStack.pop();
            if (node->left) nodeStack.push(node->left);
            if (node->right) nodeStack.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
