## Valid Palindrome
Firstly, I come up with the idea that using a stack to save the value of each character,
however, I face several problems:

1. if I ignore the charactor that is not alphanumric, the stack will totally different from
the original string.
2. the problem need to ignore the case of letter, which means we need to do double operation
for charactor in string and in stack.
3. we need O(n) space to store the characters.

Then, I found there is an much easier way to solve that:
just using two pointers, one for the start of the string and one for the end of the string.
we just need to compare the character pointed by the two pointer.
But we still face two problem:

1. how to judge whether a character is alphanumric or not.
2. how to change cases in c++.

Then I found two functions: isalnum() and tolower(), the isalnum is in ctype.h, which function
is to judge whether the input is the alphanumric. The other is to change the cases.
