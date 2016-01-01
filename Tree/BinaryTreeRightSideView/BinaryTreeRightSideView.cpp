// Source : https://leetcode.com/problems/binary-tree-right-side-view/
// Author : Yijing Bai
// Date   : 2015-12-31

/**********************************************************************************
 *
 * Given a binary tree, imagine yourself standing on the right side of it, return the
 * values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *
 *    1
 *
 * You should return [1, 3, 4].
 *
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test
 * cases.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, result, 0);
        return result;
    }

    void dfs(TreeNode* root, vector<int>& result, int depth) {
        if (!root) return;

        if (depth == result.size()) {
            result.push_back(root->val);
        }

        dfs(root->right, result, depth + 1);
        dfs(root->left, result, depth + 1);
    }

};

