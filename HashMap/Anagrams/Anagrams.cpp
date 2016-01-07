// Source : https://leetcode.com/problems/anagrams/
// Author : Yijing Bai
// Date   : 2016-01-06

/**********************************************************************************
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 *
 * Note:
 *
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 *
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 0) return result;

        unordered_map<string, vector<string>> str_map;
        for (string& str : strs) {
            string origin = str;
            sort(str.begin(), str.end());
            if (str_map.find(str) != str_map.end()) {
                str_map[str].push_back(origin);
            } else {
                str_map[str] = vector<string>();
            }
        }

        for (auto iter = str_map.begin(); iter != str_map.end(); ++iter) {
            sort(iter->second.begin(), iter->second.end());
            result.push_back(iter->second);
        }

        return result;
    }
};

int main() {
	Solution s;
	vector<string> input{""};
	s.groupAnagrams(input);

}
