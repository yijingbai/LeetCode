// Source : https://leetcode.com/problems/restore-ip-addresses/
// Author : Yijing Bai
// Date   : 2016-01-09

/**********************************************************************************
 *
 * Given a string containing only digits, restore it by returning all possible valid IP
 * address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   void restore_helper(vector<string>& result, string s, string restored, int index, int count) {
        if (count > 4) return;
        if (count == 4 && index == s.length()) {
            result.push_back(restored);
            return;
        }

        for (int i = 1; i < 4; i++) {
            if (index + i > s.size()) break;

            string subip = s.substr(index, i);
            if ((subip[0] == '0' && subip.length() > 1) || (i == 3 && stoi(subip) >= 256)) continue;

            restore_helper(result, s, restored + subip + (count == 3 ? "" : "."), index + i, count + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s == "") return result;
        string restored;
        restore_helper(result, s, restored, 0, 0);
        return result;

    }


};

int main() {
    Solution s;
    s.restoreIpAddresses("1111");

}
