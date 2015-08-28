#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isPalindrome(string s) {
        if ("" == s) {
            return true;
        }
        int i = 0, j = s.size() - 1;
        while (i < s.size() && j >= 0) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    string a = "a a";
    Solution s;
    std::cout << s.isPalindrome(a) << std::endl;
}

