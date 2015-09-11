#include <vector>

using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k <= 0) return;
        k %= nums.size();
        reverse_array(nums, nums.size() - k, nums.size() - 1);
        reverse_array(nums, 0, nums.size() - k - 1);
        reverse_array(nums, 0, nums.size() - 1);
    }
private:
    void reverse_array(vector<int>& nums, int start, int end) {
        int tmp;
        while (start < end) {
            tmp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = tmp;
        }
    }
};

int main () {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    Solution s;
    s.rotate(nums, 1);
}
