## Implement strstr()
For this question, the most straightforward way to solve is brute force.
We could use two pointer, one for the haystack and one for the needle.
But there are some scenarios may easily been forget:

1. When the haystack or the needle is empty. For the needle is empty, we
need not to find the index, it should always be 0. For the haystack is empty,
if the needle is not empty, it should always be -1;
2. If needle's length is larger than the haystack. It should alway return -1;
3. Needle occur multiple times in the haystack. We should return the first match.

