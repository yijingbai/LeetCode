#[ReorderList](https://leetcode.com/problems/reorder-list/)
######No: `143`
######Tag: `LinkedList`
######Difficulty: `Medium`
Initially, I think it pretty easy, since we just need to find the medium node and reverse the right half
then we done.
However, when I implement it, I faced many problems.
First, when finding the medium node, start from `slow = head` and `fast = head` or starting from `slow = head` and `fast = head->next`
is different. For the First case, when find the medium node, like 1->2, the Medium node will be 2. And for the second one,
the medium node will be 1. It could totally make the difference.

The second problem is that I want to make the list like 1->2<-3, but it is absolte the bad choice since when the node
number is even 1->2->3->4, it is hard for us to judge the end. The easiest way is that from the median, split the
list into two. For example, for the 1->2, median is 1, we split to 1 and 2, and for 1->2->3, median is 2, and we split to
1->2 and 3. It is much easier to us. Since we just need to judge the NULL pointer.

The third problem is that when traverse is end, we may ignore the end of the list, which will cause the list never end.
so remember to set the last element to NULL to make the list end;
