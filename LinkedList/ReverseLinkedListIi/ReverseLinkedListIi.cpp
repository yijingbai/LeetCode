// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 **********************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) return head;

        int index = 1;
        ListNode* left = head;
        ListNode* right;
        ListNode* prev = left;
        while (index < m) {
            prev = left;
            left = left->next;
            ++index;
        }

        ListNode* reverse_end = left;

        right = left->next;

        int index_right = index + 1;
        ListNode* tmp;
        while (index_right <= n) {
            tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
            ++index_right;
        }

        prev->next = left;
        reverse_end->next = right;

        if (m == 1) {
            return left;
        } else {
            return head;
        }
    }
};
