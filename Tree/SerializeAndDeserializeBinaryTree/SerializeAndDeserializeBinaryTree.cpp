// Source : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author : Yijing Bai
// Date   : 2016-01-02

/**********************************************************************************
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or another
 * computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work. You
 * just need to ensure that a binary tree can be serialized to a string and this string
 * can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following tree
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 *
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary
 * tree. You do not necessarily need to follow this format, so please be creative and
 * come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 *
 * Credits:Special thanks to @Louis1992 for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
/**
Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if (!root) {
            result += "# ";
            return result;
        }

        result += to_string(root->val);
        result += " ";
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        deque<string> tokens;
        copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter(tokens));
        for (int i = 0; i < tokens.size(); i++) {
            cout << tokens[i] << endl;
        }

        return build_tree(tokens);
    }

    TreeNode* build_tree(deque<string>& node) {
         string node_val = node.front();
         node.pop_front();
         if (node_val == "#") {
            return NULL;
         } else {
            int num_val = stoi(node_val);
            TreeNode* root = new TreeNode(num_val);
            root->left = build_tree(node);
            root->right = build_tree(node);
            return root;
         }
    }
};

int main() {
	TreeNode* root = new TreeNode(0);
	TreeNode* n1   = new TreeNode(1);
	TreeNode* n2   = new TreeNode(2);
	root->left = n1;
	root->right = n2;
	Codec codec;
	string result = codec.serialize(root);
    TreeNode* new_root = codec.deserialize(result);
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
