#[RemoveDuplicatesFromSortedListIi](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
######No: `82`
######Tag: `LinkedList`
######Difficulty: `Medium`
Considering the corner case of the first node will be deleted, using a dummy head will be the best choice for
us.
The idea is that creating a dummy head and only add the node that the show count is 1. 
Cited from https://leetcode.com/discuss/12724/my-accepted-java-code , there is a easier thinking way is that
just compare the current and current->next if different, added, otherwise, keeping going next.

```
public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return null;
        ListNode FakeHead=new ListNode(0);
        FakeHead.next=head;
        ListNode pre=FakeHead;
        ListNode cur=head;
        while(cur!=null){
            while(cur.next!=null&&cur.val==cur.next.val){
                cur=cur.next;
            }
            if(pre.next==cur){
                pre=pre.next;
            }
            else{
                pre.next=cur.next;
            }
            cur=cur.next;
        }
        return FakeHead.next;
    }
```
