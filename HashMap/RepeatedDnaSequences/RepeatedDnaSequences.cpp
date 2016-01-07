// Source : https://leetcode.com/problems/repeated-dna-sequences/
// Author : Yijing Bai
// Date   : 2016-01-06

/**********************************************************************************
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for
 * example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
 * repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur
 * more than once in a DNA molecule.
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0, i = 0, ss = s.size();
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < ss)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                r.push_back(s.substr(i - 10, 10));
        return r;
    }
};
