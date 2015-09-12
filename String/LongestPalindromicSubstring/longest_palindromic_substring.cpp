class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expand_from_center(s, i, i);
            int len2 = expand_from_center(s, i, i + 1);
            int len = max(len1, len2);
            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, max_len);
    }
private:
    int expand_from_center(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
