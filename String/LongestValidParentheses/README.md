#[LongestValidParentheses](https://leetcode.com/problems/longest-valid-parentheses/)
######No: `32`
######Tag: `String`
######Difficulty: `Hard`

The idea for this problem is simple:
cited from https://leetcode.com/discuss/7609/my-o-n-solution-using-a-stack
```
Scan the string from beginning to end.
If current character is '(', push its index to the stack. If current character is ')' and the character at the index of the top of stack is '(', we just find a matching pair so pop from the stack. Otherwise, we push the index of ')' to the stack.
After the scan is done, the stack will only contain the indices of characters which cannot be matched. Then let's use the opposite side - substring between adjacent indices should be valid parentheses.
If the stack is empty, the whole input string is valid. Otherwise, we can scan the stack to get longest valid substring as described in step 3.
```

The key is that we can use the index to push into the stack so we need not to use other addtional variables.
