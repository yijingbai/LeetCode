// Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : Yijing Bai
// Date   : 2016-01-02

/**********************************************************************************
 *
 * Given a singly linked list where elements are sorted in ascending order, convert it
 * to a height balanced BST.
 *
 **********************************************************************************/
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
	TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        ListNode* rightHead = slow->next;

        if (prev) {
            prev->next = NULL;
        } else {
            head = NULL;
        }

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(rightHead);
        return root;
    }

};

int main() {
	ListNode* head = new ListNode(3);
	ListNode* n1 = new ListNode(5);
	ListNode* n2 = new ListNode(8);

	n1->next = n2;
	head->next = n1;

	Solution s;
	s.sortedListToBST(head);
}
