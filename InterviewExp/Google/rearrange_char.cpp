#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool rearrange_string(string& s) {
        if (s.empty()) return true;
        vector<int> charNums(52, 0);
        int maxNums = 0, maxIndex = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            charNums[ s[i] - 'a' ]++;
            if (maxNums < charNums[ s[i] - 'a']) {
                maxNums = charNums[ s[i] - 'a' ];
                maxIndex = i;
            }
        }

        if (maxNums > (n + 1) / 2) return false;

        string t;
        int count = 0;

        t.append(maxNums, s[maxIndex]);
        count += maxNums;
        charNums[ s[maxIndex] - 'a' ] = 0;
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            if (charNums[index] > 0) {
                t.append(charNums[index], s[i]);
                count += charNums[index];
                charNums[index] = 0;
                if (count == n) break;
            }
        }

        int half_count = (n + 1) / 2;
        for (int i = 0; i < half_count; i++) {
            s[i * 2] = t[i];
            s[i * 2 + 1] = t[half_count + i];
        }

        if (n % 2 != 0) s[n - 1] = t[half_count];
        return true;
    }

};

int main() {
    Solution s;
    string test("aaabc");
    s.rearrange_string(test);
    cout << test.c_str() << endl;

}
