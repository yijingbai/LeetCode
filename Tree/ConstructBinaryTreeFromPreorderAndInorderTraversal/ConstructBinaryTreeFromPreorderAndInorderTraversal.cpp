// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Yijing Bai
// Date   : 2016-01-01

/**********************************************************************************
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
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
#include <vector>

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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end,
        int in_start, int in_end) {
        if (pre_end < pre_start || in_end < in_start) {
            return NULL;
        }

        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);
        int in_left_start = in_start, in_left_end, in_right_start, in_right_end = in_end;
        for (int i = in_start; i <= in_end; i++) {
            if (root_val == inorder[i]) {
                in_left_end = i - 1;
                in_right_start = i + 1;
				break;
            }
        }

        int pre_left_start = pre_start + 1, pre_left_end = pre_left_start + (in_left_end - in_left_start),
        pre_right_start = pre_left_end + 1, pre_right_end = pre_end;

        root->left = buildTreeHelper(preorder, inorder, pre_left_start, pre_left_end, in_left_start, in_left_end);
        root->right = buildTreeHelper(preorder, inorder, pre_right_start, pre_right_end, in_right_start, in_right_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

    }


};

int main() {
	vector<int> pre;
	vector<int> in;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	pre.push_back(4);
	pre.push_back(5);

	in.push_back(2);
	in.push_back(1);
	in.push_back(4);
	in.push_back(3);
	in.push_back(5);

	Solution s;
	TreeNode* root = s.buildTree(pre, in);
}
