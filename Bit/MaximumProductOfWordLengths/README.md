#[MaximumProductOfWordLengths](https://leetcode.com/problems/maximum-product-of-word-lengths/)
######No: `318`
######Tag: `Medium`
######Difficulty: `Medium`

The core idea for this problem is for each character of the word, making a bit map.
And for each word that has a bit map, when the AND of map is 0, means no duplicant
char otherwise, there are duplicant char.
