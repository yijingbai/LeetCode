// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Yijing Bai
// Date   : 2016-01-02

/**********************************************************************************
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate
 * between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        node_queue.push(NULL);
        bool from_left = true;
        vector<int> level;
        while (!node_queue.empty()) {
            TreeNode* current = node_queue.front();
            node_queue.pop();
            if (current) {
                if (from_left) {
                    level.push_back(current->val);
                } else {
                    level.insert(level.begin(), current->val);
                }

                if (current->left) {
                    node_queue.push(current->left);
                }
                if (current->right) {
                    node_queue.push(current->right);
                }
            } else {
                from_left ^= true; //flip the boolean value
                result.push_back(level);
                vector<int> new_level;
                swap(level, new_level);
                if (!node_queue.empty()) {
                    node_queue.push(NULL);
                }
            }


        }
    }
};
