// Source : https://leetcode.com/problems/reorder-list/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>

/**
Definition for singly-linked list.
 */
struct ListNode {
    i
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* begin;
        ListNode* end;
        ListNode* dummy_head;
        ListNode* slow;
        ListNode* fast;
        ListNode* tmp;
        dummy_head = new ListNode(-1);
        begin = head;
        slow = head;
        fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow) {
            fast = slow->next;
            slow->next = NULL;

            slow = fast;
            fast = fast->next;
            slow->next = NULL;
        }

        while (fast) {
            tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }

        end = slow;

        ListNode* dummy_head_p = dummy_head;

        while (begin || end) {

            if (begin) {
                dummy_head_p->next = begin;
                begin = begin->next;
                dummy_head_p = dummy_head_p->next;
            }


            if (end) {
                dummy_head_p->next = end;
                end = end->next;
                dummy_head_p = dummy_head_p->next;
            }
        }

        dummy_head_p->next = NULL;

        head->next = dummy_head->next->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution s;
    s.reorderList(head);

}
