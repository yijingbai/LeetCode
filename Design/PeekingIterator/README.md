#[PeekingIterator](https://leetcode.com/problems/peeking-iterator/)
######No: `284`
######Tag: `Design`
######Difficulty: `Medium`
Initially, I have no idea of this problem. Then I found the key is to return the peek.
And the most trivial solution is that when peek is called, directly making a new iterator
from this pointer and return its next. And for the hasNext and next, just do original
operation. This solution seems very beautiful, but I think it performance will be bad since
it need to make a new iterator.

Another way is to cache the next value and take a flag. 
