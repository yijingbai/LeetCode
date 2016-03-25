// Source : https://leetcode.com/problems/expression-add-operators/
// Author : Yijing Bai
// Date   : 2016-03-24

/**********************************************************************************
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the digits so
 * they evaluate to the target value.
 *
 * Examples:
 * "123", 6 -> ["1+2+3", "1*2*3"]
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 *
 * Credits:Special thanks to @davidtan1890 for adding this problem and creating all
 * test cases.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        for (int i=1; i<=num.size(); i++) {
            string s = num.substr(0, i);
            long cur = stol(s);
            if (to_string(cur).size() != s.size()) continue;
            dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
        }

        return res;
    }
private:
    void dfs(vector<string>& res, const string& num,
             const int target, string cur, int pos, const long cv,
             const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i = pos + 1; i <= num.size(); i++) {
                string t = num.substr(pos, i - pos);
                long now = stol(t);
                if (to_string(now).size() != t.size()) continue;
                dfs(res, num, target, cur+'+'+t, i, cv + now, now, '+');
                dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
                dfs(res, num, target, cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }
};
