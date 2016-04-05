// Source : https://leetcode.com/problems/remove-invalid-parentheses/
// Author : Yijing Bai
// Date   : 2016-04-05

/**********************************************************************************
 *
 * Remove the minimum number of invalid parentheses in order to make the input string
 * valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Examples:
 *
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 *
 * Credits:Special thanks to @hpplayer for adding this problem and creating all test
 * cases.
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
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for (char ch : s) {
      if (ch == '(') {
        ++left;
      } else if (ch == ')') {
        if (left > 0) {
          --left;
        } else {
          ++right;
        }
      }
    }
    res.clear();
    dfs(s, 0, left, right, 0, "");
    return res;
  }

private:
  void dfs(const string& s, int start, int left, int right,
           int open, string path) {
    if (start == s.length()) {
      if (left == 0 && right == 0 && open == 0) {
        res.push_back(path);
      }
      return;
    }
    if (left < 0 || right < 0 || open < 0) return;

    char c = s[start];
    if (c == '(') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= left; ++i) {
          dfs(s, start + i + 1, left - i - 1, right, open, path);
        }
      }

      dfs(s, start + 1, left, right, open + 1, path + c);
    } else if (c == ')') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= right; ++i) {
          dfs(s, start + i + 1, left, right - i - 1, open, path);
        }
      }

      dfs(s, start + 1, left, right, open - 1, path + c);
    } else {
      dfs(s, start + 1, left, right, open, path + c);
    }
  }

  vector<string> res;
};
