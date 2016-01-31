#[TextJustification](https://leetcode.com/problems/text-justification/)
######No: `68`
######Tag: `String`
######Difficulty: `Hard`

The key point is calculate the number of space and deal with the corner case.
Cited from https://leetcode.com/problems/text-justification/
```
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
}
For each line, I first figure out which words can fit in. According to the code,
these words are words[i] through words[i+k-1]. Then spaces are added between the 
words. The trick here is to use mod operation to manage the spaces that can't be
 evenly distrubuted: the first (L-l) % (k-1) gaps acquire an additional space.
```
