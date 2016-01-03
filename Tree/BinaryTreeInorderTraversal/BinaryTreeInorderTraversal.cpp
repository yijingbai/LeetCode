// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Yijing Bai
// Date   : 2016-01-03

/**********************************************************************************
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
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
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 * OJ's Binary Tree Serialization:
 *
 * The serialization of a binary tree follows a level order traversal, where '#'
 * signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 *
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 *
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> node_stack;
        if (!root) return result;
        TreeNode* current = root;
        while (current) {
            node_stack.push_back(current);
            current = current->left;
        }
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.back();
            node_stack.pop_back();
            result.push_back(node->val);

            if (node->right) {
                current = node->right;
                while (current) {
                    node_stack.push_back(current);
                    current = current->left;
                }
            }
        }
        return result;
    }
};
