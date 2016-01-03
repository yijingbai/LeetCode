#[PopulatingNextRightPointersInEachNode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
######No: `116`
######Tag: `Tree`
######Difficulty: `Medium`
This is the same interview question of TripAdvisor. The key idea is that if the parent
node is already connect, we can easily use root->next to get to the same level subtree
and connect the node between. What we need to do is just `cur->right->next = cur->next->left`

However, from https://leetcode.com/discuss/7327/a-simple-accepted-solution
there is an awesome solution.

```
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
```
