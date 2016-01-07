#[RepeatedDnaSequences](https://leetcode.com/problems/repeated-dna-sequences/)
######No: `187`
######Tag: `HashMap BitManipulation`
######Difficulty: `Medium`

I did not finished it by myself. The model solution is very beautiful.
Cited From https://leetcode.com/discuss/25399/clean-java-solution-hashmap-bits-manipulation

```
The key point is that it is not doing hash, it is doing the exact coding of a 10-letter sequence into a 4-bytes number, which is simply not possible for any generic string, but is possible for strings in this problem because they can have only 4 differfent characters.

In more detail:

If two objects have same hash it means that they may or may not be equal (though two equal objects are required to have same hash). So hashing is not enough here (like calling just "AACCCCCGGG".hashCode() and storing it in the map), because there can be another (different) string with same hash and the program will output wrong result.

We also cannot store the 10-letter substrings themselves because they consume too much memory and the program will exceed memory limit.

So, instead of hashing or storing strings themselves the solution converts 10 letter string into 4-bytes integer (which is much smaller than string in terms of consumed memory). This would not be possible if the string could contain all 26 letters of English alphabet for example. But it is possible for our case, because there can be only 'A', 'C', 'G' and 'T' letters.

So we have only 4 possible letters, and we can use as little bits as possible to store each character of our 10-letter string. We really need only 2 bits (bits, not bytes) for this. Specifically the solution uses the following coding:

0 = 00 (bits in binary number system) = 'A'

1 = 01 (bits in binary number system) = 'C'

2 = 10 (bits in binary number system) = 'G'

3 = 11 (bits in binary number system) = 'T'

Note that since there 10 letters and each letter requires only 2 bits, we will need only 10 * 2= 20 bits to code the string (which is less then size of integer in java (as well as in all othere popular languages), which is 4 bytes = 32 bits).

For example, this is how "AACCTCCGGT" string will be coded:

A A C C T C C G G T

00 00 01 01 11 01 01 10 10 11 = 00000101110101101011 (binary) = 23915 (decimal)
```

But the implementation is more beautiful in https://leetcode.com/discuss/24478/i-did-it-in-10-lines-of-c 

```
The main idea is to store the substring as int in map to bypass the memory limits.

There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.

Why? It's easier to code.

A is 0x41, C is 0x43, G is 0x47, T is 0x54. Still don't see it? Let me write it in octal.

A is 0101, C is 0103, G is 0107, T is 0124. The last digit in octal are different for all four letters. That's all we need!

We can simply use s[i] & 7 to get the last digit which are just the last 3 bits, it's much easier than lookup table or switch or a bunch of if and else, right?

We don't really need to generate the substring from the int. While counting the number of occurrences, we can push the substring into result as soon as the count becomes 2, so there won't be any duplicates in the result.

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}
```
