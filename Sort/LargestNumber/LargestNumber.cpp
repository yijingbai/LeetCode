// Source : https://leetcode.com/problems/largest-number/
// Author : Yijing Bai
// Date   : 2016-01-14

/**********************************************************************************
 *
 * Given a list of non negative integers, arrange them such that they form the largest
 * number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an
 * integer.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<num.size(); i++){
            ans += to_string(num[i]);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};
