// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author : Yijing Bai
// Date   : 2016-01-17

/**********************************************************************************
 *
 * Given n non-negative integers representing the histogram's bar height where the
 * width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 *
 **********************************************************************************/


class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> index;
        for (int i = 0; i < n; ++i) {
            while (!index.empty() && height[index.top()] > height[i]) {
                int h = height[index.top()]; index.pop();
                int l = index.empty() ? -1 : index.top();
                area = max(area, h * (i - l - 1));
            }
            index.push(i);
        }
        return area;
    }
};

