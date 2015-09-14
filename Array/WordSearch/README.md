#(Word Search)[https://leetcode.com/problems/word-search/]
###### Tag: `Array`
###### Difficuty: `Medium`
This question is a typical backtracking problem. The my initial way is to is depth first seach,
however, found it is very difficult to implement it, my code is like:

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        map<pair<int, int>, bool> pos_map;
        queue<pair<int, int>> target_queue;
        int i = 0;
        
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                i = 0;
                while (i < word.size()) {
                    if (word[i] != board[x][y]) {
                        return false;
                    } else {
                        if (x - 1 >= 0 && pos_map.find(make_pair(x - 1, y)) == pos_map.end()) {
                            target_queue.push(make_pair(x - 1, y));
                        }
                        if (y + 1 < n && pos_map.find(make_pair(x, y + 1)) == pos_map.end()) {
                            target_queue.push(make_pair(x, y + 1));
                        }
                        if (x + 1 < m && pos_map.find(make_pair(x + 1, y)) == pos_map.end()) {
                            target_queue.push(make_pair(x + 1, y));
                        }
                        if (y - 1 >= 0 && pos_map.find(make_pair(x, y - 1)) == pos_map.end()) {
                            target_queue.push(make_pair(x, y - 1));
                        }
                        while (!target_queue.empty()) {
                            pair next_node = target_queue.front();
                            target_queue.pop();
                            i++;
                            pos_map.insert(*next_node, true);
                            if (board[next_node.first()][next_node.second()] != board[i]) {
                                
                            }
                        }
                    }
                    
                }
            }
        }
    }
};
```

However, after I check the discussion, I found it is a backtrack problem, the best
solution is to is DFS + backtracking. We could write a recursive function and check
every element.
