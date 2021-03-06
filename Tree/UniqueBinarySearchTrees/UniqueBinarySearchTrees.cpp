// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : Yijing Bai
// Date   : 2016-01-03

/**********************************************************************************
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values
 * 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int G[10000];
		G[0] = G[1] = 1;

        for(int i=2; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                G[i] += G[j-1] * G[i-j];
            }
        }
        // for (int i = 2; i <= n; ++i) {
        //     for (int j = 1; j <= i; ++j) {
        //         G[i] += G[j-1] * G[i-j];
        //     }
        // }
        return G[n];
    }
};

int main() {
	Solution s;
	s.numTrees(3);
}

