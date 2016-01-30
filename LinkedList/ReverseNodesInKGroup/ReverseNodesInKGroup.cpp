// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Yijing Bai
// Date   : 2016-01-29

/**********************************************************************************
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its
 * modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should
 * remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        int len = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            len++;
        }
        p = head;

        for (int start = 1, end = 1 + k - 1; end <= len && start <= len; start = end + 1, end = start + k - 1) {
            p = reverseBetween(p, start , end);
        }
        return p;
    }

private:
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


int main() {
	ListNode* head = new ListNode(1);
	ListNode* head2 = new ListNode(2);
    head->next = head2;
	Solution s;
	s.reverseKGroup(head, 2);
}
