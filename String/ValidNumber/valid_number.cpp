#include <string>

using std::string;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        bool is_float = false;
        bool has_number = false;
        bool is_signed = false;
        bool is_exp = false;

        while (i < s.size()) {
            if (' ' == s[i]) {

                if (is_float && !has_number) {
                    return false;
                }
                i++;
                if (i < s.size() && ' ' != s[i] && (has_number || is_signed || is_float)) {
                    return false;
                }
                continue;
            }

            if ('+' == s[i] || '-' == s[i]) {
                if ((has_number && !is_exp)) {
                    return false;
                }
                if (is_float && !is_exp) {
                    return false;
                }
                if (is_exp && i - 1 >= 0 && s[i-1] != 'e') {
                    return false;
                }
                i++;
                if (i >= s.size()) {
                    return false;
                }
                is_signed = true;
                continue;
            }

            if ('e' == s[i]) {
                if (!has_number || is_exp) {
                    return false;
                }
                is_exp = true;
                i++;
                if (i >= s.size()) {
                    return false;
                }
                if (i < s.size() && !isdigit(s[i]) && s[i] != '+' && s[i] != '-') {
                    return false;
                }
                continue;
            }

            if ('.' == s[i]) {
                if (is_float || is_exp) {
                    return false;
                }
                is_float = true;
                i++;
                if (!has_number && i >= s.size()) {
                    return false;
                }
                if (i >= s.size()) {
                    return true;
                }
                continue;
            }

            if (isdigit(s[i])) {
                has_number = true;
                i++;
                continue;
            }

            if (!isdigit(s[i]) && '.' != s[i] && ' ' != s[i] && 'e' != s[i]
                && '+' != s[i] && '-' != s[i]) {
                return false;
            }

            i++;


        }
        if (i == s.size() && has_number) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    s.isNumber(" 005047e+6");
}
