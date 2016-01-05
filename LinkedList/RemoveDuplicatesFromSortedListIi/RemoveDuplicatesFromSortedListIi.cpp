// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Yijing Bai
// Date   : 2016-01-05

/**********************************************************************************
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving
 * only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* current = head;
        ListNode* prev = head;
        ListNode* new_next = NULL;
        ListNode* new_head = NULL;

        ListNode* dummy_head = new ListNode(-1);
        ListNode* dp = dummy_head;

        int prev_val = head->val;
        int count = 0;

        while (current) {
            if (current->val != prev_val) {
                prev_val = current->val;
                if (count == 1) {
                    dp->next = prev;
                    dp = dp->next;
                    dp->next = NULL;
                }
                prev = current;
                count = 1;
            } else {
                ++count;
            }

            current = current->next;
        }

        if (count == 1) {
            dp->next = prev;
            dp = dp->next;
            dp->next = NULL;
        }

        return dummy_head->next;
    }
};
