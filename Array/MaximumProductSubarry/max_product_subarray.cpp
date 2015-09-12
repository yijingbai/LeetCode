#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_value = nums[0], min_value = nums[0], max_final = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int mx = max_value, mn = min_value;
            max_value = max(max(mx * nums[i], nums[i]), mn * nums[i]);
            min_value = min(min(mx * nums[i], nums[i]), mn * nums[i]);
            max_final = max(mx, max_final);
        }
        return max_final;
    }
};

int main() {
    Solution s;
    vector<int> input;
    input.push_back(6);
    input.push_back(3);
    input.push_back(-10);
    input.push_back(0);
    input.push_back(2);
    s.maxProduct(input);
}
