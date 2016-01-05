#[LinkedListCycleIi](https://leetcode.com/problems/linked-list-cycle-ii/)
######No: `142`
######Tag: `LinkedList`
######Difficulty: `Medium`
I did not solve this by myself. Cited From https://leetcode.com/discuss/9908/o-n-solution-by-using-two-pointers-without-change-anything
There is a very detailed explantion:
```
my solution is like this: using two pointers, one of them one step at a time. 
another pointer each take two steps. Suppose the first meet at step k,the length of the Cycle is r.
so..2k-k=nr,k=nr Now, the distance between the start node of list and the start node of cycle is s.
the distance between the start of list and the first meeting node is k(the pointer which wake one step 
at a time waked k steps).the distance between the start node of cycle and the first meeting node is m, 
so...s=k-m, s=nr-m=(n-1)r+(r-m),here we takes n = 1..so, using one pointer start from the start node of list,
another pointer start from the first meeting node, all of them wake one step at a time, 
the first time they meeting each other is the start of the cycle.

t make a easier understanding. Suppose the first meet at step k,the distance between the start node of
list and the start node of cycle is s, and the distance between the start node of cycle and the first 
meeting node is m. Then 2k = (s + m + n1r) = 2(s + m + n2r) ==> s + m = nr. Steps moving from start node 
to the start of the cycle is just s, moving from m by s steps would be the start of the cycle, covering
 n cycles. In other words, they meet at the entry of cycle.
```
