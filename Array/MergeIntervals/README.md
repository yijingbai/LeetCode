#[MergeIntervals](https://leetcode.com/problems/merge-intervals/)
######No: `56`
######Tag: `Array`
######Difficulty: `Hard`
Although it is a hard question, I think it is pretty easy. Just sort the overlap by its start point
and use two pointer to mark start and end. If the interval is overlaped, the start and end pointer
will move to the new corresponding position.
