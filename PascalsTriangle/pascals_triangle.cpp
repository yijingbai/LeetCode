class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            int len = i + 1;
            vector<int> item;
            for (int j = 0; j < len; j++) {
                if (len < 3 || j == 0 || j == len - 1) {
                    item.push_back(1);
                    continue;
                }
                item.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res.push_back(item);
        }
        return res;
    }
};
