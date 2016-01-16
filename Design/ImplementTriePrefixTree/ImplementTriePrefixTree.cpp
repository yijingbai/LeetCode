// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : Yijing Bai
// Date   : 2016-01-15

/**********************************************************************************
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
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

    TrieNode *next[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }


};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->next[c - 'a'] == NULL) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p && p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix);
    }

private:
    TrieNode* root;

    TrieNode* find(string key) {
         TrieNode* p = root;

         for (int i = 0; i < key.size() && p != NULL; ++i) {
             p = p->next[key[i] - 'a'];
         }

         return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

