#[Subsets](https://leetcode.com/problems/subsets/)
######No: ``
######Tag: `Array Backtracking`
######Difficulty: `medium`
This is a typical backtracking problem. To solve this, the idea is that
each time, we remove the last element of the array and then we recursively
get the result of subset of the array that removed the last element.When
we get the result, We add every subset without the last element into the 
result set. Then we add the last element to every subset. Therefore, we
could get the final result.
