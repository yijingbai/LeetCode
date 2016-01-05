#[ReverseLinkedListIi](https://leetcode.com/problems/reverse-linked-list-ii/)
######No: `92`
######Tag: `LinkedList`
######Difficulty: `Medium`

This is the first medium question that I can right in one shot!
The idea is simple. And the tricky part is that range.

There are two cases:
1. m == 1. For this case, the first node will be reversed. Therefore, we can not return it as the head node.
In his case, the head node will be the node at index n, so we return it as the head.
2. m != 1. For this case, we just return first node as the head node.

In addition, the sequence of

```
prev->next = left;
reverse_end->next = right;
```
is important. If we swap them, it will be wrong, since when m == 1, the prev == reverse_end. Its next should point
to right, not left. 
