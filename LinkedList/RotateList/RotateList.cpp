// Source : https://leetcode.com/problems/rotate-list/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 *
 *
 *
 *
 *
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        ListNode* tail = head;
        int length = 1;
        while(tail->next) {
            tail = tail->next;
            ++length;
        }

        tail->next = head;

        k %= length;
        for (int i = 0; i < length - k; ++i) {
            tail = tail->next;
        }

        ListNode* new_head = tail->next;
        tail->next = NULL;

        return new_head;

    }
};
