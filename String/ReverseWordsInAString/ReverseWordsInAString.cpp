#include <iostream>

using std::string;

class Solution {
public:
    void reverseWords(string &s) {
        string answer;
        int prev = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (' ' == s[i]) {
                prev = i;
            } else if (' ' == s[i - 1] || i == 0) {
                if (answer.size() != 0) {
                    answer += ' ';
                }
                for (int j = i; j < prev; j++) {
                    answer += s[j];
                }
                prev = --i;
            }
        }
        s = answer;
    }
};

int main() {
    string test = "1 ";
    Solution s;
    s.reverseWords(test);
    std::cout <<"|||"<< test.c_str() <<"|||"<< std::endl;
}
