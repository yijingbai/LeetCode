// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Yijing Bai
// Date   : 2016-01-02

/**********************************************************************************
 *
 * Given a binary tree
 *
 *     struct TreeLinkNode {
 *       TreeLinkNode *left;
 *       TreeLinkNode *right;
 *       TreeLinkNode *next;
 *     }
 *
 * Populate each next pointer to point to its next right node. If there is no next
 * right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same
 * level, and every parent has two children).
 *
 * For example,
 * Given the following perfect binary tree,
 *
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> node_queue;
        node_queue.push(root);
        node_queue.push(NULL);
        while (!node_queue.empty()) {
            TreeLinkNode* node = node_queue.front();
            node_queue.pop();

            if (node) {
                if (node->left && node->right) {
                    node_queue.push(node->left);
                    node_queue.push(node->right);
                    node->left->next = node->right;
                    if (node->next) {
                        node->right->next = node->next->left;
                    }
                }
            } else {
                if (!node_queue.empty()) {
                    node_queue.push(NULL);
                }
            }
        }
    }
};

