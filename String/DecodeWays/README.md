#[DecodeWays](https://leetcode.com/problems/decode-ways/)
######No: `91`
######Tag: `String DP`
######Difficulty: `Medium`

Initally, I just using a simple backtracking approach. However, I found it too slow.
Cited from https://leetcode.com/discuss/21090/a-concise-dp-solution
I found it is a DP problem.
```
class Solution {
public:
    int numDecodings(string s) {
        if (!s.size() || s.front() == '0') return 0;
        // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
        int r1 = 1, r2 = 1;
    
        for (int i = 1; i < s.size(); i++) {
            // zero voids ways of the last because zero cannot be used separately
            if (s[i] == '0') r1 = 0;
    
            // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                r1 = r2 + r1;
                r2 = r1 - r2;
            }
    
            // one-digit letter, no new way added
            else {
                r2 = r1;
            }
        }
    
        return r1;
    }
    
};
```
This is optimized the memory. I think the https://leetcode.com/discuss/8527/dp-solution-java-for-reference
is easier to understand using bottom up DP:
```
public class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if (n == 0) return 0;

        int[] memo = new int[n+1];
        memo[n]  = 1;
        memo[n-1] = s.charAt(n-1) != '0' ? 1 : 0;

        for (int i = n - 2; i >= 0; i--)
            if (s.charAt(i) == '0') continue;
            else memo[i] = (Integer.parseInt(s.substring(i,i+2))<=26) ? memo[i+1]+memo[i+2] : memo[i+1];

        return memo[0];
    }
}
```

The base case is memo[n] = 1 and memo[n-1] = s[n-1] != '0' ? 1 : 0;

and the formula is that:
```
    memo[i] = memo[i+1] + memo[i+2] When s.substr(i, i+2) <= 26
    memo[i] = memo[i+1] When otherwise
```
The reason is that for the first case, the two digit could interprete to a word
