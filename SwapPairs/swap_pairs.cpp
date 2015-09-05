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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* dp = dummy_head, *p = head, *t;
        while (NULL != p && NULL != p->next) {
            t = p->next->next;
            dp->next = p->next;
            dp = dp->next;
            dp->next = p;
            dp = dp->next;
            p = t;
        }
        if (NULL != p) {
            dp->next = p;
            dp->next->next = NULL;
        } else {
            dp->next = NULL;
        }
        return dummy_head->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    ListNode* res = s.swapPairs(head);
    while (res) {
        std::cout << res->val << " -> ";
        res = res->next;
    }
}
