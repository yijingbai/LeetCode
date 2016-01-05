// Source : https://leetcode.com/problems/partition-list/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come
 * before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two
 * partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode* dummy_head_less = new ListNode(-1);
        ListNode* dummy_head_bigger_equal = new ListNode(-1);
        ListNode* dummy_head_less_p = dummy_head_less;
        ListNode* dummy_head_bigger_equal_p = dummy_head_bigger_equal;

        ListNode* current = head;
        while (current) {
            if (current->val < x) {
                dummy_head_less_p->next = current;
                dummy_head_less_p = dummy_head_less_p->next;
            } else {
                dummy_head_bigger_equal_p->next = current;
                dummy_head_bigger_equal_p = dummy_head_bigger_equal_p->next;
            }
            current = current->next;
        }

        dummy_head_less_p->next = NULL;
        dummy_head_bigger_equal_p->next = NULL;

        ListNode* new_head;
        if (!dummy_head_less_p) {
            new_head = dummy_head_bigger_equal->next;
        } else {
            dummy_head_less_p->next = dummy_head_bigger_equal->next;
            new_head = dummy_head_less->next;
        }
        return new_head;
    }
};

int main () {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    n1->next = n2;

    Solution s;
    ListNode* res = s.partition(n1, 0);
}
