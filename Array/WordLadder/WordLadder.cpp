// Source : https://leetcode.com/problems/word-ladder/
// Author : Yijing Bai
// Date   : 2016-01-18

/**********************************************************************************
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find the
 * length of shortest transformation sequence from beginWord to endWord, such that:
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
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 *
 **********************************************************************************/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        unordered_set<string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        return ladderLengthHelper(words1, words2, wordList, 1);
    }

    int ladderLengthHelper(unordered_set<string>& words1, unordered_set<string>& words2,
            unordered_set<string>& dict, int level) {
        if (words1.empty()) return 0;
        if (words1.size() > words2.size()) {
            return ladderLengthHelper(words2, words1, dict, level);
        }
        unordered_set<string> words3;

        for (auto it = words1.begin(); it != words1.end(); ++it) {
            string word = *it;
            for (char& c : word) {
                char tmp = c;
                for (c = 'a'; c <= 'z'; ++(c)) {
                    if (words2.find(word) != words2.end()) return level + 1;
                    else if (dict.find(word) != dict.end()) {
                        dict.erase(word);
                        words3.insert(word);
                    }
                }
                c = tmp;
            }
        }
        return ladderLengthHelper(words2, words3, dict, level + 1);
    }


};

