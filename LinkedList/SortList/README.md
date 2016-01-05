#[SortList](https://leetcode.com/problems/sort-list/)
######No: `148`
######Tag: `LinkedList`
######Difficulty: `Medium`

I use a quick sort approach. Implementing this gives me a very very hard time.
There are bunches of problems happend.
1. After partition, the left part and the right part both could be empty. If we do not deal with
this corner case, we will have error. When the left part is empty, will need to return the pivotal_begin
as the start. When the right part is empty_
2. When there is same value element, my approach will skip the same value and find the new pivotal begin
and pivotal end. It gives me a very hard time. The reason is that in the loop that find the pivotal start and
end, initially, I just write if the current equal to the pivotal value, set it as the pivotal. Actually, it is
wrong, since when there are multiple pivotals, the pivotal beginnning will keep moving util to the end;
