// Source : https://leetcode.com/problems/h-index-ii/
// Author : Yijing Bai
// Date   : 2016-01-08

/**********************************************************************************
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending order?
 * Could you optimize your algorithm?
 *
 *   Expected runtime complexity is in O(log n) and the input is sorted.
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************/

/*
A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, mid;
        int len = citations.size();
        while (left <= right) {
            mid = (left + right) >> 1;

            //h = len - mid, so if h == citations, means h papers have at least h citations, since
            //it is sorted and all the h papers on the right have more citations.
            if (citations[mid] == len - mid) return citations[mid];
            // if h < citations, means h is small and many number of citations could fullfil this,
            // so we need to increase h, which means make mid small, so we let right = mid - 1
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return (len - (right + 1));
    }
};
