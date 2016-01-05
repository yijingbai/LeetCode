#[InsertionSortList](https://leetcode.com/problems/insertion-sort-list/)
######No: `147`
######Tag: `LinkedList`
######Difficulty: `Medium`
The idea for this problem is easy. But the implementation may have many subtle problem.
The idea that using a dummy head as the sorted part. And for the new node, we just
need to find the smaller one and insert into the right place.

The first corner case is that it need to insert into the head.
And the other corner case is that ineed to insert into the end.

Moreover, remeber to set the prev pointer to the right position. Not just the dummy pointer.
