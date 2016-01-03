// Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author : Yijing Bai
// Date   : 2016-01-03

/**********************************************************************************
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store
 * values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
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
    vector<TreeNode *> generateTrees(int n) {
        return helper(1,n);
    }

    vector<TreeNode*> helper(int s, int e) {
        if (s > e) {
             return vector<TreeNode*>(1,NULL);
        }

        vector<TreeNode*> result;
        for (int i=s; i <= e; ++i) {
            vector<TreeNode*> left, right;
                left = helper(s,i-1);
                right = helper(i+1,e);
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        result.push_back(root);
                    }
                }
        }

        return result;
    }
};
