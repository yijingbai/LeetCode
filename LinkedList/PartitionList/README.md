#[PartitionList](https://leetcode.com/problems/partition-list/)
######No: `86`
######Tag: `LinkedList`
######Difficulty: `Medium`

This problem is not difficult. We easily using two dummy head. We store the node that less than
the val and the other one store the node that bigger or equal to the val. Therefore, we just
need to connect the first one with the second one.
The speical case is that if the first one is empty, we need to return the second one as the 
new head;
