#[RemoveDuplicateLetters](https://leetcode.com/problems/remove-duplicate-letters/)
######No: `316`
######Tag: `Stack Greedy`
######Difficulty: `Medium`

There are two ways to solve this problem.
1. Greedy Approach, Cited from https://leetcode.com/discuss/73761/a-short-o-n-recursive-greedy-solution :
```
Given the string s, the greedy choice (i.e., the leftmost letter in the answer) is the smallest s[i], s.t. the suffix s[i .. ] contains all the unique letters. (Note that, when there are more than one smallest s[i]'s, we choose the leftmost one. Why? Simply consider the example: "abcacb".)

After determining the greedy choice s[i], we get a new string s' from s by

removing all letters to the left of s[i],
removing all s[i]'s from s.
We then recursively solve the problem w.r.t. s'.

The runtime is O(26 * n) = O(n).

public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26];
        int pos = 0; // the position for the smallest s[i]
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}
```


2. Stack approach, cited from https://leetcode.com/discuss/73824/short-16ms-solution-using-stack-which-can-optimized-down-4ms
```
Your idea, just a bit shorter.

Similar to but slightly shorter than zhiqing_xiao's, which I didn't see before. Main differences are my sentinel (the space char), that I don't have the unnecessary results.back() == c check, and the imho better variable names.

Takes 4 ms as well.

string removeDuplicateLetters(string s) {
    int ahead[256] = {};
    for (char c : s)
        ahead[c]++;

    string result = " ";
    bool inresult[256] = {};

    for (char c : s) {
        ahead[c]--;
        if (inresult[c])
            continue;
        while (c < result.back() && ahead[result.back()]) {
            inresult[result.back()] = false;
            result.pop_back();
        }
        result += c;
        inresult[c] = true;
    }

    return result.substr(1);
}
```
