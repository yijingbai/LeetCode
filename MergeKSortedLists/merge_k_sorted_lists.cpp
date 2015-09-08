#include <iostream>
#include <vector>

using std::vector;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int left = 0, right = lists.size() - 1;
        while (right > 0) {
            int left = 0;
            while (left < right) {
                lists[left] = merge_2_lists(lists[left], lists[right]);
                left++;
                right--;
            }
        }
        return lists[0];
    }
private:
    ListNode* merge_2_lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode(0);
        ListNode* l1_p = l1, *l2_p = l2;
        while (l1 && l2) {
            if (l1_p->val <= l2_p->val) {
                dummy_node->next = l1_p;
                l1_p = l1_p->next;
            } else {
                dummy_node->next = l2_p;
                l2_p = l2_p->next;
            }
            dummy_node = dummy_node->next;
        }
        if (l1) {
            dummy_node->next = l1;
        }
        if (l2) {
            dummy_node->next = l2;
        }
        return dummy_node->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    Solution s;
    s.mergKLists(lists);
}

