// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Author : Yijing Bai
// Date   : 2016-04-02

/**********************************************************************************
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant
 * space solution?
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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* first = NULL, *second = NULL;

        TreeNode* temp = NULL;
        while (root != NULL) {
            if (root->left != NULL) {
                temp = root->left;
                while (temp->right != NULL && temp->right != root) {
                    temp = temp->right;
                }
                if (temp->right != NULL) {
                    if (pre != NULL && pre->val > root->val) {
                        if (first == NULL) {first = pre; second = root;}
                        else {second = root;}
                    }
                    pre = root;
                    temp->right = NULL;
                    root = root->right;
                } else {
                    temp->right = root;
                    root = root->left;
                }
            } else {
                if (pre != NULL && pre->val > root->val) {
                    if (first == NULL) {first = pre; second = root;}
                    else {
                        second = root;
                    }
                }
                pre = root;
                root = root->right;
            }
        }

        if (first != NULL && second != NULL) {
            int t = first->val;
            first->val = second->val;
            second->val = t;
        }

    }
};
