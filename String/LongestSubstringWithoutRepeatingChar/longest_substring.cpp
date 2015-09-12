#include <iostream>

using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int char_map[256] = {-1};
        int max_length = 0;
        int i = 0;
        for (int t = 0; t < 256; t++) {
            char_map[t] = -1;
        }
        for (int j = 0; j < s.size(); j++) {
            if (char_map[s[j]] >= i) {
                i = char_map[s[j]] + 1;
            }
            max_length = max(max_length, j - i + 1);
            char_map[s[j]] = j;
        }
        return max_length;
    }
};


int main () {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("au") << std::endl;
}
