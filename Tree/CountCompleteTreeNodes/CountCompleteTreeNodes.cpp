// Source : https://leetcode.com/problems/count-complete-tree-nodes/
// Author : Yijing Bai
// Date   : 2015-12-31

/**********************************************************************************
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely
 * filled, and all nodes in the last level are as far left as possible. It can have
 * between 1 and 2h nodes inclusive at the last level h.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h < 0) return 0;
        if (height(root->right) == h - 1) {
            return (1 << h) + countNodes(root->right);
        } else {
            return (1 << (h - 1)) + countNodes(root->left);
        }
    }

    int height(TreeNode* root) {
        return !root ? -1 : 1 + height(root->left);
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(3);
	root->left = n1;
	root->right = n2;
	Solution s;
	s.countNodes(root);
}
