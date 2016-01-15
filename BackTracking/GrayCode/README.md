#[GrayCode](https://leetcode.com/problems/gray-code/)
######No: `89`
######Tag: `Backtracking`
######Difficulty: `Medium`
There are three ways to solve this problem.
The first approach is the backtracking.
```
class Solution {
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if(k==0){
            result.push_back(bits.to_ulong());
        }
        else{
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};
```

The second approach is :
```
public ArrayList<Integer> grayCode(int n) {
    ArrayList<Integer> arr = new ArrayList<Integer>();
    arr.add(0);
    for(int i=0;i<n;i++){
        int inc = 1<<i;
        for(int j=arr.size()-1;j>=0;j--){
            arr.add(arr.get(j)+inc);
        }
    }
    return arr;
}
```

The third approach is:
```
You can also view more solution on Github

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        return ans;
    }
};
I try to give a simple proof here. Let's denote i^(i>>1) as f(i). To proof f(i) is the ith gray code, we only need to prove the following statements:

f(0) = 0
(i) and f(i+1) only differs in one digit
f(i) is bijective, e.g. f(i) = f(j) if and only if i = j.
The first one is obvious.

For the second , f(i) ^ f(i+1) = i^(i>>1)^(i+1)^((i+1)>>1) = (i^(i+1)) ^ ((i^(i+1)) >> 1). Let's denote g(i) = i^(i+1), g(i) has the form of 0000111...111. So f(i) ^ f(i+1) = g(i) ^ g(i)>>1 = 00001000...000.

The third part can be proved alike.
```
