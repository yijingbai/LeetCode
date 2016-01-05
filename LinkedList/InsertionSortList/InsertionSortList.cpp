// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : Yijing Bai
// Date   : 2016-01-05

/**********************************************************************************
 *
 * Sort a linked list using insertion sort.
 *
 *
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* current = head->next;

        ListNode* dummyhead_p = dummyhead->next;
        dummyhead_p->next = NULL;

        ListNode* pre = dummyhead;
        ListNode* next;
        bool inserted = false;
        while (current) {
            next = current->next;
            inserted = false;
            while (dummyhead_p) {
                if (current->val < dummyhead_p->val) {
                    insertNode(pre, dummyhead_p, current, true);
                    inserted = true;
                    break;
                } else {
                    pre = dummyhead_p;
                }
                dummyhead_p = dummyhead_p->next;
            }

            if (!inserted) {
                insertNode(NULL, pre, current, false);
            }
            dummyhead_p = dummyhead->next;
            pre = dummyhead;
            current = next;
        }

        return dummyhead->next;
    }

    void insertNode(ListNode* pre, ListNode* target, ListNode* node, bool is_left) {
        if (!target) return;
        if (is_left) {
            if (!pre) return;
            pre->next = node;
            node->next = target;
        } else {
            node->next = target->next;
            target->next = node;
        }
    }
};

int main() {
     ListNode* n1 = new ListNode(3);
     ListNode* n2 = new ListNode(4);
     ListNode* n3 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    Solution s;
    s.insertionSortList(n1);
}
