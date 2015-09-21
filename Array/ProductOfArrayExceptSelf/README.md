#[ProductOfArrayExceptSelf](https://leetcode.com/problems/product-of-array-except-self/)
######No: `238`
######Tag: `Array`
######Difficulty: `Medium`

To solve this question in O(n), the idea is that result of a index is the product of
the left part and the right part of this index. So we first traverse the array and
calculate the product of the right part of one index. Then we traverse again to generate
the final result.
