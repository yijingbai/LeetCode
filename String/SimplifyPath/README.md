#[SimplifyPath](https://leetcode.com/problems/simplify-path/)
######No: `71`
######Tag: `Medium`
######Difficulty: `Medium`

The idea for this problem is simple. Just using a stack to keep track the full path.
And when there is a `..` just pop out the element. But be careful, when pop out the
element, we need to check the size of the stack. When the stack is empty, we should
not pop.
