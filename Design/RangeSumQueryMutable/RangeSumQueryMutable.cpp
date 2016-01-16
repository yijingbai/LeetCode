// Source : https://leetcode.com/problems/range-sum-query-mutable/
// Author : Yijing Bai
// Date   : 2016-01-15

/**********************************************************************************
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i
 * ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i to val.
 *
 * Example:
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 * Note:
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed
 * evenly.
 *
 **********************************************************************************/


class NumArray {
public:

    struct SegTreeNode {
        int start, end;
        SegTreeNode *left, *right;
        int sum;

        SegTreeNode(int s, int e) :
            start(s), end(e), left(NULL), right(NULL) {}
    };

    SegTreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        SegTreeNode* node = new SegTreeNode(start, end);
        if (start == end) {
            node->sum = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            node->left = build(nums, start, mid);
            node->right = build(nums, mid + 1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    void update(SegTreeNode* root, int pos, int val) {
        if (root->start == root->end) {
            root->sum = val;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (pos <= mid) {
            update(root->left, pos, val);
        } else {
            update(root->right, pos, val);
        }
        root->sum = root->left->sum + root->right->sum;
    }

    int sumRange(SegTreeNode* root, int start, int end) {
        if (root->end == end && root->start == start) {
            return root->sum;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return sumRange(root->left, start, end);
        } else if (start >= mid + 1) {
            return sumRange(root->right, start, end);
        } else {
             return sumRange(root->right, mid + 1, end) + sumRange(root->left, start, mid);
        }
    }

    NumArray(vector<int> &nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

private:
    SegTreeNode *root;


};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

