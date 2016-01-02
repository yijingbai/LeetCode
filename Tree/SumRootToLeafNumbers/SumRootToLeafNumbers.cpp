// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : Yijing Bai
// Date   : 2016-01-01

/**********************************************************************************
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could
 * represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 *
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
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
    i
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


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

    void sumNumbersHelper(TreeNode* root, vector<vector<int>>& route_set, vector<int>& route) {
        if (!root) {
            return;
        }
        route.push_back(root->val);
        if (!root->left && !root->right) {
            route_set.push_back(route);
        }
        sumNumbersHelper(root->left, route_set, route);
        sumNumbersHelper(root->right, route_set, route);
        route.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> route;
        sumNumbersHelper(root, result, route);
        int total_sum = 0;
        for (int i = 0; i < result.size(); i++) {
            int sum = 0;
            int prefix = 1;
            for (int j = result[i].size() - 1; j >= 0; j--) {
                sum += result[i][j] * prefix;
                prefix *= 10;
            }
            total_sum += sum;
        }
        return total_sum;
    }
};



int main() {
    TreeNode* root = new TreeNode(2);
    TreeNode* n1 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(0);
    root->left = n1;
    root->right = n2;

    Solution s;
    s.sumNumbers(root);
}
