## Two Sum
For this problem, the easiest way to solve is brute force.
We just need to tried every element and check whether the rest of the item is equal to target - current.
However, this way will O(n^2).

A better solution is that we could use a map to store the value of the item as the key and the index as the
value. Then for every new element, we just need to find whether there is an element that in the map could equal
to target - current. Then it will be O(n) with space use O(n).

