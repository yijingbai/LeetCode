#[WildcardMatching](https://leetcode.com/problems/wildcard-matching/)
######No: `44`
######Tag: `String`
######Difficulty: `Hard`
Cited from https://leetcode.com/discuss/52274/three-solutions-iterative-16ms-180ms-modified-recursion-88ms
```
The reason that the iterative solution is much faster for this case is we only need to save (and deal with) the positions (iStar for s, jStar for p) of the last "" we met. We only need to do traceback using iStar and jStar and all the previous "" can be ignored since the last "" will cover all the traceback cases for the previous "". What we need to do are

if the current p character is '' (i.e. p[j]==''), then we update iStar and jStar with the cureent i and j values. iStar/jStar will be used for traceback. Also we do --i to start the depth first search with the case that '*' represents a null string.
if p[j]!='', then we check if mismatch occurs (i.e. p[j]!=s[i] and p[j]!='?'), if so we check if we met a '' before (iStar>=0), if not, then we return false since no match can achieve. Otherwise, we traceback to the positions at which the last '*' happens and do the next possible dfs search (i.e. i = iStar++; j = jStar; remember to update iStar too to save the i position to try in the next traceback).
The loop will quit when we reach the end of s. At last, we need to skip all the '*' in p to see if we can reach the end of p. if so, match, otherwise mismatch
class Solution {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            { 
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};
A DP solution is also given here. It has O(N^2) time complexity and O(N) space

class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.size(), sLen = s.size(), i, j, k, cur, prev;
        if(!pLen) return sLen == 0;
        bool matched[2][sLen+1];
        fill_n(&matched[0][0], 2*(sLen+1), false);

        matched[0][0] = true;
        for(i=1; i<=pLen; ++i)
        {
            cur = i%2, prev= 1-cur;
            matched[cur][0]= matched[prev][0] && p[i-1]=='*';
            if(p[i-1]=='*') for(j=1; j<=sLen; ++j) matched[cur][j] = matched[cur][j-1] || matched[prev][j];
            else for(j=1; j<=sLen; ++j)            matched[cur][j] =  matched[prev][j-1] && (p[i-1]=='?' || p[i-1]==s[j-1]) ;
        }
            return matched[cur][sLen];
    }
};
A recursion version. A typical recursion version will give us TLE due to too many unnecessary recursive calls. As we explained, all the traceback recursive calls at the '' we met (except the last '') are unneccessary and should be avoided. In the below version, we use recLevel to track the recursion level (i.e the total '' we met) and we also use curLevel to save the order of '' we currently process. If it is not the last '' we met (i.e if(recLevel>curLevel+1) ), then we will return false directly ( if(recLevel>curLevel+1) return false;) to skip all unneccessary recursion call at the '' before the last '*'.

class Solution {
private:
    bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
    {
        int sSize = s.size(), pSize = p.size(), i, curLevel = recLevel;
        bool first=true;
        while(si<sSize && (p[pi]==s[si] || p[pi]=='?')) {++pi; ++si;} //match as many as possible
        if(pi == pSize) return si == sSize; // if p reaches the end, return
        if(p[pi]=='*')
        { // if a star is met
            while(p[++pi]=='*'); //skip all the following stars
            if(pi>=pSize) return true; // if the rest of p are all star, return true
            for(i=si; i<sSize; ++i)
            {   // then do recursion
                if(p[pi]!= '?' && p[pi]!=s[i]) continue;
                if(first) {++recLevel; first = false;}
                if(helper(s, p, i, pi, recLevel)) return true;
                if(recLevel>curLevel+1) return false; // if the currently processed star is not the last one, return
            }
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int recLevel = 0;
        return helper(s, p, 0, 0, recLevel);
    }
};

```
