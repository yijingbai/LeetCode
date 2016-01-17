// Source : https://leetcode.com/problems/insert-interval/
// Author : Yijing Bai
// Date   : 2016-01-17

/**********************************************************************************
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals
 * (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start
 * times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty()) return {newInterval};
        Interval *start, *end;

        Interval lowInterval(INT_MIN, newInterval.start);
        auto low = lower_bound(intervals.begin(), intervals.end(), lowInterval,
                [](const Interval& l, const Interval& r) {return l.end < r.end;});

        if (low == intervals.end()) {
            copy(intervals.begin(), intervals.end(), back_insert_iterator<vector<Interval>>(res));
            res.push_back(newInterval);
            return res;
        }

        Interval highInterval(newInterval.end, INT_MAX);
        auto high = upper_bound(intervals.begin(), intervals.end(), highInterval,
                                 [](const Interval& l, const Interval& r) {return l.start < r.start;});
        if (high == intervals.begin()) {
            res.push_back(newInterval);
            copy(intervals.begin(), intervals.end(), back_insert_iterator<vector<Interval>>(res));
            return res;
        }

        Interval mergedInterval(min(newInterval.start, low->start), max(newInterval.end, (high-1)->end));
        copy(intervals.begin(), low, back_insert_iterator<vector<Interval>>(res));
        res.push_back(mergedInterval);
        copy(high, intervals.end(), back_insert_iterator<vector<Interval>>(res));
        return res;

    }
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    auto it = intervals.begin();
    for(; it!=intervals.end(); ++it){
        if(newInterval.end < (*it).start) //all intervals after will not overlap with the newInterval
            break;
        else if(newInterval.start > (*it).end) //*it will not overlap with the newInterval
            ret.push_back(*it);
        else{ //update newInterval bacause *it overlap with the newInterval
            newInterval.start = min(newInterval.start, (*it).start);
            newInterval.end = max(newInterval.end, (*it).end);
        }
    }
    // don't forget the rest of the intervals and the newInterval
    ret.push_back(newInterval);
    for(; it!=intervals.end(); ++it)
        ret.push_back(*it);
    return ret;
}
