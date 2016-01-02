// Source : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : Yijing Bai
// Date   : 2016-01-01

/**********************************************************************************
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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

    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder, int post_start, int post_end,
        int in_start, int in_end) {
        if (post_end < post_start || in_end < in_start) {
            return NULL;
        }

        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);
        int in_left_start = in_start, in_left_end, in_right_start, in_right_end = in_end;
        for (int i = in_start; i <= in_end; i++) {
            if (root_val == inorder[i]) {
                in_left_end = i - 1;
                in_right_start = i + 1;
				break;
            }
        }

        int post_left_start = post_start, post_left_end = post_left_start + (in_left_end - in_left_start),
        post_right_start = post_left_end + 1, post_right_end = post_end - 1;

        root->left = buildTreeHelper(postorder, inorder, post_left_start, post_left_end, in_left_start, in_left_end);
        root->right = buildTreeHelper(postorder, inorder, post_right_start, post_right_end, in_right_start, in_right_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};

