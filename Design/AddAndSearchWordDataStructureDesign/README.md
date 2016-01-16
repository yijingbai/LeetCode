#[AddAndSearchWordDataStructureDesign](https://leetcode.com/problems/add-and-search-word-data-structure-design/)
######No: `211`
######Tag: `Design Trie`
######Difficulty: `Medium`
This is a typical Trie Problem. The different part is the query function. In the query, we are allowed
to use . to represent any words. Cited from https://leetcode.com/discuss/39022/80ms-clear-c-code-with-detailed-explanations
```
This problem is an application of the Trie data structure. In the following, it is assumed that you have solved Implement Trie (Prefix Tree).

Now, let's first look at the TrieNode class. I define it as follows.

class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26); 
    }
};
The field isKey is to label whether the string comprised of characters starting from root to the current node is a key (word that has been added). In this problem, only lower-case letters a - z need to be considered, so each TrieNode has at most 26 children. I store it in an array of TrieNode*: children[i] corresponds to letter 'a' + i. The remaining code defines the constructor of the TrieNode class.

Adding a word can be done in the same way as in Implement Trie (Prefix Tree). The basic idea is to create a TrieNode corresponding to each letter in the word. When we are done, label the last node to be a key (set isKey = true). The code is as follows.

void addWord(string word) {
    TrieNode* run = root;
    for (char c : word) {
        if (!(run -> children[c - 'a']))
            run -> children[c - 'a'] = new TrieNode();
        run = run -> children[c - 'a']; 
    }
    run -> isKey = true;
}
By the way, root is defined as private data of WordDictionary:

private:
    TrieNode* root;
And the WordDictionary class has a constructor to initialize root:

WordDictionary() {
    root = new TrieNode();
}
Now we are left only with search. Let's do it. The basic idea is still the same as typical search operations in a Trie. The critical part is how to deal with the dots .. Well, my solution is very naive in this place. Each time when we reach a ., just traverse all the children of the current node and recursively search the remaining substring in word starting from that children. So I define a helper function query for search that takes in a string and a starting node. And the initial call to query is like query(word, root).

By the way, I pass a char* instead of string to query and it greatly speeds up the code. So the initial call to query is actually query(word.c_str(), root).

Now I put all the codes together below. Hope it to be useful!
```
