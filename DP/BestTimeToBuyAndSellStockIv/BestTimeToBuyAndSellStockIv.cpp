// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author : Yijing Bai
// Date   : 2016-03-25

/**********************************************************************************
 *
 * Say you have an array for which the ith element is the price of a given stock on day
 * i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the
 * stock before you buy again).
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all test
 * cases.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len / 2) {
            int ans = 0;
            for (int i = 1; i < len; ++i) {
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }
        int hold[k + 1];
        int rele[k + 1];
        for (int i = 0; i <= k; ++i) {
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i = 0; i < len; ++i) {
            cur = prices[i];
            for (int j = k; j > 0; --j) {
                rele[j] = max(rele[j], hold[j] + cur);
                hold[j] = max(hold[j], rele[j - 1] - cur);
            }
        }
        return rele[k];

    }
};
