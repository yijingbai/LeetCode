## Reverse Words in a String

For this question the easiest way is using a new string to store the result
string.Then we could use a pointer from the end of the string to reverse every
word.
There are some corner cases we need to concern:

1. For the string that has traling spaces. To avoid this, we should first check 
whether the current char is space. If so, we could change our end pointer to here.
2. Another problem is that we need add space after every word, but the single word 
need not to add space.
