class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> fwd, bwd;
        fwd.insert(beginWord);
        bwd.insert(endWord);

        unordered_map<string, vector<string>> hs;

        BFS(fwd, bwd, wordList, false, hs);

    }

    void BFS(unordered_set<string> forward, unordered_set<string> backward,
            unordered_set<string> dict, bool swap, unordered_map<string, vector<string>> hs) {
        if (forward.empty() || backward.empty()) return;

        if (forward.size() > backward.size()) {
            BFS(backward, forward, dict, !swap, hs);
        }

        for(string& word : forward) hs.erase(word);
        for(string& word : backward) hs.erase(word);

        unordered_set<string> set3;

        for (string& str : forward) {
            string tmp = str;
            for (char& c : tmp) {
                for (c = 'a'; c <= 'z'; ++c) {
                    if (!backward[tmp] && !dict[tmp]) continue;

                    string key = !swap ? str : tmp;
                    string val = !swap ? tmp : str;

                    if (!hs[key]) hs[key] = vector<string>();

                    if (backward[tmp]) {
                        hs[key].push_back(val);
                        isConnected = true;
                    }

                    if (!isConnected && dict.contains(tmp)) {
                        hs[key].push_back(val);
                        set3.insert(tmp);
                    }
            }
        }

        if (!isConnected) {
             BFS(set3, backward, dict, swap, hs);
        }
    }

    void DFS(vector<vector<string>>& result, vector<string> tmp, string start, string end,
            unordered_map<string, vector<string>> hs) {
        if (start == end) {
            result.push_back(tmp);
            return;
        }

        if (!hs[start]) return;

        for (string& s : hs[start]) {
            tmp.push_back(s);
            DFS(result, tmp, s, end, hs);
            tmp.remove(tmp.end() - 1);
        }
    }

private:
    bool is_connected;
};
