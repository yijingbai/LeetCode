#[ContainsDuplicateIii](https://leetcode.com/problems/contains-duplicate-iii/)
######No: `220`
######Tag: `Array`
######Difficulty: `Medium`

I did not solve this by myself. Cited from https://leetcode.com/discuss/38177/java-o-n-lg-k-solution:
```
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
        // -t <= x - nums[i] <= t;
        auto pos = window.lower_bound(nums[i] - t); // x >= nums[i] - t
        if (pos != window.end() && *pos - nums[i] <= t) // x <= nums[i] + t
               return true;
        window.insert(nums[i]);
    }
    return false;
}

This problem requires to maintain a window of size k of the previous values that can be queried for value ranges. The best data structure to do that is Binary Search Tree. As a result maintaining the tree of size k will result in time complexity O(N lg K). In order to check if there exists any value of range abs(nums[i] - nums[j]) to simple queries can be executed both of time complexity O(lg K)

Here is the whole solution using TreeMap.

public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums == null || nums.length == 0 || k <= 0) {
            return false;
        }

        final TreeSet<Integer> values = new TreeSet<>();
        for (int ind = 0; ind < nums.length; ind++) {

            final Integer floor = values.floor(nums[ind] + t);
            final Integer ceil = values.ceiling(nums[ind] - t);
            if ((floor != null && floor >= nums[ind])
                    || (ceil != null && ceil <= nums[ind])) {
                return true;
            }

            values.add(nums[ind]);
            if (ind >= k) {
                values.remove(nums[ind - k]);
            }
        }

        return false;
    }
}
```
