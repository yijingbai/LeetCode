#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index;
        if ("" == needle) {
            return 0;
        }
        if ("" == haystack && "" != needle) {
            return -1;
        }

        int starter = 0;
        for (int i = 0, j = 0; i < haystack.size() && j < needle.size();) {
            char haystack_char = haystack[i];
            char target_char = needle[j];
            if (haystack_char != target_char) {
                j = 0;
                i = ++starter;
                continue;
            }
            if (haystack_char == target_char) {
                if (j == 0) {
                    index = i;
                }
                if (j == needle.size() - 1) {
                    return index;
                }
                i++;
                j++;
                continue;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    std::cout << s.strStr("mississippi", "a") << std::endl;;
}

