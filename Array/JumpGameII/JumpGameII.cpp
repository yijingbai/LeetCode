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
