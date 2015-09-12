class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int result = 0;
        int maxDiv10 = INT_MAX / 10;
        int i = 0;
        while (i < str.size() && ' ' == str[i]) {
            i++;
        }

        if ('+' == str[i]) {
            sign = 1;
            i++;
        } else if ('-' == str[i]) {
            sign = -1;
            i++;
        }

        while (i < str.size() && isdigit(str[i])) {
                int digit = (int) str[i] - '0';
                if (result > maxDiv10 || result == maxDiv10 && digit >= 8) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                result = result * 10 + digit;
                i++;
        }
        return sign * result;
    }
};

