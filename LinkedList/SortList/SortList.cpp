// Source : https://leetcode.com/problems/sort-list/
// Author : Yijing Bai
// Date   : 2016-01-04

/**********************************************************************************
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int pivotal = head->val;
        ListNode* partitioned = partition(head, pivotal);

        ListNode* current = partitioned;
        ListNode* prev = NULL;
        ListNode* right = NULL;
        ListNode* pivotal_begin = NULL;
        ListNode* pivotal_end = NULL;

        bool is_left_empty = false;
        bool found_pivotal_begin = false;
        while (current) {

            if (current->val == pivotal) {
                if (prev && !found_pivotal_begin) {
                    prev->next = NULL;
                } else if (!prev) {
                    is_left_empty = true;
                }
                if (!found_pivotal_begin) {
                    pivotal_begin = current;
                    found_pivotal_begin = true;
                } else {
                    pivotal_end = current;
                }
            }
            if (current->val > pivotal) {
                right = current;
                prev->next = NULL;
                pivotal_end = prev;
                break;
            }

            prev = current;
            current = current->next;
        }

        ListNode* new_head;
        if (!is_left_empty) {
            ListNode* sortedLeft = sortList(partitioned);
            current = sortedLeft;
            while (current->next) {
                current = current->next;
            }
            current->next = pivotal_begin;
            new_head = sortedLeft;
        } else {
            new_head = pivotal_begin;
        }
        ListNode* sortedRight = sortList(right);
        if (pivotal_end) {
            pivotal_end->next = sortedRight;
        }

        return new_head;

    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution s;
    s.sortList(n1);
}
