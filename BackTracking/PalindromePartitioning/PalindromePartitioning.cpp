// Source : https://leetcode.com/problems/palindrome-partitioning/
// Author : Yijing Bai
// Date   : 2016-01-14

/**********************************************************************************
 *
 * Given a string s, partition s such that every substring of the partition is a
 * palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 *
 * Return
 *
 *   [
 *     ["aa","b"],
 *     ["a","a","b"]
 *   ]
 *
 *
 **********************************************************************************/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;

        vector<string> cur;
        par_helper(res, cur, s, 0);

        return res;
    }

    void par_helper(vector<vector<string>>& res, vector<string>& cur, string s, int begin) {
        if (begin == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = begin; i < s.size(); i++) {
            if (is_pal(s, begin, i)) {
                cur.push_back(s.substr(begin, i - begin + 1));
                par_helper(res, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }

    bool is_pal(string& s, int i, int e) {
        while (i <= e) {
            if (s[i] != s[e]) return false;
            ++i;
            --e;
        }
        return true;
    }
};

