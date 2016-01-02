#[SumRootToLeafNumbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
######No: `129`
######Tag: `Tree`
######Difficulty: `Medium`
This question is just depth first search but we need to get all the path from the root to the leaf node.
To do this, we need a helper funtion to generate this and then we can calulate the result.
There is a problem that initionally I just want to add the path in to the path_set when the root is empty,
however, it will double the result since every node has two empty child node. Then I change to when the node
is leaf, then add the path into the pathset, this also obey the defination.
