// Source : https://leetcode.com/problems/simplify-path/
// Author : Yijing Bai
// Date   : 2016-01-10

/**********************************************************************************
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * click to show corner cases.
 *
 * Corner Cases:
 *
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as
 * "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 **********************************************************************************/


class Solution {
public:
    string simplifyPath(string path) {

        stringstream ss(path);
        string item;
        vector<string> paths;
        while (getline(ss, item, '/')) {
            if (item == "" || item == ".") continue;
            if (item == "..") {
                if (!paths.empty()) paths.pop_back();
                continue;
            } else {
                paths.push_back(item);
            }
        }

        string res;

        for (auto v : paths) {
            res += "/" + v;
        }

        if (res == "") res += "/";

        return res;

    }
};
