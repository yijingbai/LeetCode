// Source : https://leetcode.com/problems/merge-intervals/
// Author : Yijing Bai
// Date   : 2016-01-17

/**********************************************************************************
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 **********************************************************************************/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end(),
                [](const Interval& l, const Interval& r){return l.start < r.start;});

        int min_v = intervals[0].start, max_v = intervals[0].end;
        for (Interval i : intervals) {
            if (i.start <= max_v) {
                max_v = max(i.end, max_v);
            } else {
                res.push_back(Interval(min_v, max_v));
                min_v = i.start;
                max_v = i.end;
            }
        }
        res.push_back(Interval(min_v, max_v));
        return res;
    }
};

