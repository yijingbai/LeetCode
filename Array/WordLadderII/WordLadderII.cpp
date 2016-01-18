// Source : https://leetcode.com/problems/word-ladder-ii/
// Author : Yijing Bai
// Date   : 2016-01-18

/**********************************************************************************
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find all
 * shortest transformation sequence(s) from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 *
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Return
 *
 *   [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 *   ]
 *
 * Note:
 *
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 *
 *
 *
 *
 **********************************************************************************/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
        std::vector<std::vector<std::string> > paths;
        std::vector<std::string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        std::unordered_set<std::string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        std::unordered_map<std::string, std::vector<std::string> > nexts;
        bool words1IsBegin = false;
        if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
            getPath(beginWord, endWord, nexts, path, paths);
        return paths;
    }
private:
    bool findLaddersHelper(
        std::unordered_set<std::string> &words1,
        std::unordered_set<std::string> &words2,
        std::unordered_set<std::string> &dict,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        bool &words1IsBegin) {
        words1IsBegin = !words1IsBegin;
        if (words1.empty())
            return false;
        if (words1.size() > words2.size())
            return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
        for (auto it = words1.begin(); it != words1.end(); ++it)
            dict.erase(*it);
        for (auto it = words2.begin(); it != words2.end(); ++it)
            dict.erase(*it);
        std::unordered_set<std::string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            std::string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp)
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                        else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                *ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
    }
    void getPath(
        std::string beginWord,
        std::string &endWord,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        std::vector<std::string> &path,
        std::vector<std::vector<std::string> > &paths) {
        if (beginWord == endWord)
            paths.push_back(path);
        else
            for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
};


// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
//         unordered_set<string> fwd, bwd;
//         fwd.insert(beginWord);
//         bwd.insert(endWord);
//
//         unordered_map<string, vector<string>> hs;
//
//         BFS(fwd, bwd, wordList, false, hs);
//
//         vector<vector<string>> result;
//         if (!isConnected) return result;
//
//         vector<string> tmp;
//         tmp.push_back(beginWord);
//
//         DFS(result, tmp, beginWord, endWord, hs);
//
//         return result;
//
//     }
//
//     void BFS(unordered_set<string> forward, unordered_set<string> backward,
//             unordered_set<string>& dict, bool swap, unordered_map<string, vector<string>>& hs) {
//         if (forward.empty() || backward.empty()) return;
//
//         if (forward.size() > backward.size()) {
//             BFS(backward, forward, dict, !swap, hs);
//         }
//
// 		for (auto it = forward.begin(); it != forward.end(); ++it)
//             dict.erase(*it);
//         for (auto it = backward.begin(); it != backward.end(); ++it)
//             dict.erase(*it);
//
//         unordered_set<string> set3;
//
//         for (const string& str : forward) {
//             string tmp = str;
//             for (char& c : tmp) {
//                 char tmpc = c;
//                 for (c = 'a'; c <= 'z'; ++c) {
//                     if ((backward.find(tmp) == backward.end())
//                         && (dict.find(tmp) == dict.end())) continue;
//
//                     string key = !swap ? str : tmp;
//                     string val = !swap ? tmp : str;
//
//                     if (hs.find(key) == hs.end()) hs[key] = vector<string>();
//
//                     if (backward.find(tmp) != backward.end()) {
//                         hs[key].push_back(val);
//                         isConnected = true;
//                     }
//
//                     if (!isConnected && dict.find(tmp) != dict.end()) {
//                         hs[key].push_back(val);
//                         set3.insert(tmp);
//                     }
//                 }
//                 c = tmpc;
//             }
//         }
//
//         if (!isConnected) {
//              BFS(set3, backward, dict, swap, hs);
//         }
//     }
//
//     void DFS(vector<vector<string>>& result, vector<string>& tmp, string& start, string& end,
//             unordered_map<string, vector<string>>& hs) {
//         if (start == end) {
//             result.push_back(tmp);
//             return;
//         }
//
//         if (hs.find(start) == hs.end()) return;
//
//         for (string& s : hs[start]) {
//             tmp.push_back(s);
//             DFS(result, tmp, s, end, hs);
//             tmp.erase(tmp.end() - 1);
//         }
//     }
//
// private:
//     bool isConnected;
// };

int main () {
    unordered_set<string> dict{"a", "b", "c"};

    Solution s;
    s.findLadders("a", "c", dict);
}
