// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author : Yijing Bai
// Date   : 2016-01-12

/**********************************************************************************
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 *
 * search(word) can search a literal word or a regular expression string containing
 * only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 * click to show hint.
 *
 * You should be familiar with how a Trie works. If not, please work on this problem:
 * Implement Trie (Prefix Tree) first.
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/


class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!(run -> children[c - 'a']))
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run -> isKey;
    }
};

