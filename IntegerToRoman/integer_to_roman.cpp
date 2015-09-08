#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string intToRoman(int num) {
        string roman_character[] = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL" "X", "IX" "V", "IV" "I"
        };
        int num_roman[] = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        int i = 0;
        int c = 0;
        string result = "";
        while (num != 0) {
            c = num / num_roman[i];
            for (int j = 0; j < c; j++) {
                result += roman_character[i];
                num -= num_roman[i];
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution s;
    string res = s.intToRoman(4);
    cout << res << endl;
}
