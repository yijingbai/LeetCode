#[PermutationsIi](https://leetcode.com/problems/permutations-ii/)
######No: `47`
######Tag: `BackTracking`
######Difficulty: `Medium`
In this problem, the most important issue is that the paramerter nums and the swamp.
Cited from https://leetcode.com/discuss/25279/a-simple-c-solution-in-only-20-lines
this is a concise solution.
```
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
```

However, when I implement by myself, I write nums to the nums reference. And this makes
it could not AC 
