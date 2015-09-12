#[SetMatrixZeroes](https://leetcode.com/problems/set-matrix-zeroes/)
######No: `73`
######Tag: `Array`
######Difficulty: `Medium`
The most naive way to solve this problem is to store all the number that has been
changed to zero, this will cost the space O(MN) and if we only store the position
of the 0, the space will be much less, deduced to O(M+N), but if we want to solve
it in constant time, we need to have a little trick: use the fist row and first 
column to store the zero lines and column.Therefore, we only need to spend constant
space to store whether the line and column it self are zero.
