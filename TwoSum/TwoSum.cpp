#include <vector>
#include <map>
#include <utility>
#include <iostream>

using std::vector;
using std::map;
using std::pair;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_index_map;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            if (num_index_map.end() !=
                    num_index_map.find(target - current)) {
                vector<int> res;
                res.push_back(num_index_map[target - current] + 1);
                res.push_back(i + 1);
                return res;
            }
            num_index_map.insert(std::make_pair(current, i));
        }
    }
};

int main() {
    Solution s;
    vector<int> sample;
    sample.push_back(2);
    sample.push_back(7);
    sample.push_back(11);
    sample.push_back(15);
    vector<int> res = s.twoSum(sample, 9);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
}
