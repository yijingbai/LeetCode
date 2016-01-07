#[Anagrams](https://leetcode.com/problems/anagrams/)
######No: `49`
######Tag: `HashMap String`
######Difficulty: `Medium`
Initionally I have no idea with this problem.
After cited from https://leetcode.com/discuss/58561/share-my-short-java-solution
The idea is pretty simple. Since each group contains all the anagram of the string. If we sort them,
they actually is the same. Therefore, we just use the sorted string as the key and the anagram list
as the value. If found the key, push the string into the list. Otherwise, make a new list and put
the element in.
