// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Yijing Bai
// Date   : 2015-12-31

/**********************************************************************************
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * return [1,2,3].
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
 * Definition for a binary tree node. */
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> node_stack;
        if (!root) return result;
        node_stack.push_back(root);
        while (!node_stack.empty()) {
            TreeNode* current = node_stack.back();
            node_stack.pop_back();
            if (current->right) {
                node_stack.push_back(current->right);
            }
            if (current->left) {
                node_stack.push_back(current->left);
            }

            result.push_back(current->val);
        }
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	Solution s;
	s.preorderTraversal(root);
}

