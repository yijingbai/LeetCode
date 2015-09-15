#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int minr = binary_search_min(nums, target);
        int maxr = binary_search_max(nums, target);
        vector<int> res;
        res.push_back(minr);
        res.push_back(maxr);
        return res;
    }
private:
    int binary_search_min(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = right + (left - right) / 2;
            if (target == nums[mid]) right = mid;
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
    int binary_search_max(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = right + (left - right + 1) / 2;
            if (target == nums[mid]) left = mid;
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[right] == target ? right : -1;
    }
};

int main () {
    Solution s;
    vector<int> input;
    input.push_back(2);
    input.push_back(2);

    s.searchRange(input, 2);

}

