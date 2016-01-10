#[SearchA2dMatrixIi](https://leetcode.com/problems/search-a-2d-matrix-ii/)
######No: `240`
######Tag: `D&Q BinarySearch`
######Difficulty: `Medium`

This is a BinarySearch problem. However, my solution is just O(m + n), so I think we could come
up a faster solution.
The O(m + n) solution's idea is that check the top right element. If this element equal to the
target, return true, else if the target is less than the element, since the row is sorted, we know
the total raw is less than the target, we goes to the next row. If the target is larger than the
element, since the column is also sorted, we go to the next column. Repeating this, we will
find the target, the worst time is O(m + n).
