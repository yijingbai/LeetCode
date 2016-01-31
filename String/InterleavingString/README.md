#[InterleavingString](https://leetcode.com/problems/interleaving-string/)
######No: `97`
######Tag: `String`
######Difficulty: `Hard`

There is nice solution cited from
https://leetcode.com/problems/interleaving-string/
```
bool isInterleave(string s1, string s2, string s3) {

    if(s3.length() != s1.length() + s2.length())
        return false;

    bool table[s1.length()+1][s2.length()+1];

    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }

    return table[s1.length()][s2.length()];
}
Here is some explanation:

DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position,
and s2 is at jth position. 0th position means empty string.

So if both s1 and s2 is currently empty, s3 is empty too, and it is considered interleaving.
 If only s1 is empty, then if previous s2 position is interleaving and current s2 position
 char is equal to s3 current position char, it is considered interleaving. similar idea 
applies to when s2 is empty. when both s1 and s2 is not empty, then if we arrive i, j from 
i-1, j, then if i-1,j is already interleaving and i and current s3 position equal, it s 
interleaving. If we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j 
and current s3 position equal. it is interleaving.
```
