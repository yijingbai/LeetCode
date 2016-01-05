#[RotateList](https://leetcode.com/problems/rotate-list/)
######No: `61`
######Tag: `LinkedList`
######Difficulty: `Medium`
The meaning of rotate is confusing initially. We can imaging that we can move the list from left to the right,
at mean time, the node at the end we come back to the beginning. 
Therefore, we should first count the number of nodes of the list. Then we connect the last node to the first
node. What we need to do next is that calculate the k = k % length. The reason is that k could bigger than
the length. But if k == length, it is same to not rotate the list. So we just need to get the mod value.

Then we need to find the new head. The way is that we find the new end. We just need to move the pointer
lenth - k times and it will point to the end of the list. Then we set its next as the beginning and
set it next as NULL.
