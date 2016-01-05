#[LinkedListCycle](https://leetcode.com/problems/linked-list-cycle/)
######No: `141`
######Tag: `LinkedList`
######Difficulty: `Medium`
This is a typical question. To finding the cycle, the easiest way is that using two pointer. The slow
pointer move 1 step each time while the fast pointer move 2 step each time. Since the distance of
fast pointer and slow pointer will increase by 1 each time, So if there is a loop, the fast pointer
and slow pointer could finally equal. If the fast pointer equal to NULL, means there is no loop.
