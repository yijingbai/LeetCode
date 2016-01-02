// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Yijing Bai
// Date   : 2016-01-02

/**********************************************************************************
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like:
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * click to show hints.
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the
 * next node of a pre-order traversal.
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>

using namespace std;
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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* dummyHead = new TreeNode(-1);
		TreeNode* currentHead = dummyHead;
        dfs(root, currentHead);
        *root = *dummyHead->right;
    }

	TreeNode* dfs(TreeNode* root, TreeNode* dummyHead) {
        if (!dummyHead) return dummyHead;
        if (!root) return dummyHead;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        root->right = NULL;
        dummyHead->right = root;
        TreeNode* last = dfs(left, dummyHead->right);
        TreeNode* finally = dfs(right, last);
        return finally;
    }

};

int main() {
	TreeNode* root = new TreeNode(1);
	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(3);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(5);


	n2->left = n4;
	n1->left = n2;
	n1->right = n3;
	root->left = n1;

	Solution s;
	s.flatten(root);
	cout << "hello" << endl;
}
