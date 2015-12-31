// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : Yijing Bai
// Date   : 2015-12-31

/**********************************************************************************
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (NULL != root) {
            TreeNode* current_node = root;
            while (current_node) {
                iterator_stack.push_back(current_node);
                current_node = current_node->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !iterator_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next_node = iterator_stack.back();
        iterator_stack.pop_back();
        TreeNode* tmp = next_node->right;
        while (tmp) {
            iterator_stack.push_back(tmp);
            tmp = tmp->left;
        }
        return next_node->val;
    }
private:
    vector<TreeNode*> iterator_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
