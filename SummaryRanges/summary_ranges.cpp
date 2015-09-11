class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> range_vector;
        if (nums.size() == 0) return range_vector;
        int start = 0, end = 1;
        char buffer[100];
        while (start < nums.size()) {
            if (end >= nums.size()) {
                if (start != nums.size() - 1) {
                    snprintf(buffer, 100, "%d->%d", nums[start], nums[nums.size() - 1]);
                    string item = buffer;
                    range_vector.push_back(item);
                } else {
                    snprintf(buffer, 100, "%d", nums[start]);
                    string item = buffer;
                    range_vector.push_back(item);
                }
                break;
            }
            if (nums[end] == nums[end - 1] + 1) {
                end++;
                continue;
            } else {
                if (end - 1 > start) {
                    snprintf(buffer, 100, "%d->%d", nums[start], nums[end - 1]);
                    string item = buffer;
                    range_vector.push_back(item);
                } else {
                    snprintf(buffer, 100, "%d", nums[start]);
                    string item = buffer;
                    range_vector.push_back(item);
                }
                start = end++;
            }
        }
    }
};
