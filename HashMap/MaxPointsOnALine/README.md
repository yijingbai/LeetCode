#[MaxPointsOnALine](https://leetcode.com/problems/max-points-on-a-line/)
######No: `149`
######Tag: `HashMap`
######Difficulty: `Hard`

For this problem, it is not very hard. Since a line is respresent by
y = kx + b; And k = (y1 - y2) / (x1 - x2). Therefore, if we begin
from each point and calculate the slope for the line form by this point
and every other point. If two point have same slope and they share
a common point, they must in same line. Therefore, we need to use 
a map to using the slope as the key, and the nums of point as value.
However, if the k is float, it may not accurate. Then we could use
a pair<a, b> to represent the slope.

Cited from https://leetcode.com/discuss/45105/16ms-28ms-c-solutions-with-explanations

```
s problem has a naive idea, which is to traverse all possible pairs of two points and see how many other points fall in the line determined by them. This idea is of O(n^3) time complexity and will meet TLE.

Well, let's focus on lines instead of pairs of points. Could we just find out how many points fall in all possible lines? The answer is yes. Remember that a line is determined by its slope and intercept. In fact, if two lines with the same slope share a common point, then they are just the same line. So to determine a line, we need its slope and a point.

Now comes the idea to solve this problem. We start from a specific point p, and compute all the slopes of the lines between p and the remaining points. Then those with the same slopes will be the same line. We can find out the maximum number of points fall on a line containing p. We exhaust all possible p's and record the largest number we have seen. This number is just answer.

Well, there are still two special cases to handle:

Duplicate points: a pair of duplicate points give no determined line, so we just count the number of duplicates and add them to the result.
Vertical lines: the slope of these lines is infinity mathematically. We simply set it to be INT_MAX in the following code.
Now we have the following code, using an unordered_map<float, int> slopes to record how many points fall in the line of a specific slope and containing points[i]. Since all the operations of unordered_map is O(1), this code is of O(n^2) complexity.

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> slopes;
        int maxp = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                float slope = (points[j].x == points[i].x) ? INT_MAX : 
                              (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                slopes[slope]++;
            }
            maxp = max(maxp, duplicate);
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp) 
                    maxp = slope.second + duplicate; 
        }
        return maxp;
    }
};
Well, since the representation of floating point numbers is sometimes inaccurate, we may use a more safer way to represent the slope (dy / dx), which is to record dx and dy in a pair<int, int>. However, once we use pair<int, int> for the key of the map, we cannot use an unordered_map since pair<int, int> is unhashable. We now change to map and the time complexity becomes O(n^2logn). Also, since dy = 4, dx = 2 and dy = 8, dx = 4 represents the same slope, we need to divide both of them by their gcd first.

The code is as follows. The logic is the same of the one above, just introducing pair and gcd.

class Solution { 
public: 
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> slopes;
        int maxp = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int dvs = gcd(dx, dy);
                slopes[make_pair(dx / dvs, dy / dvs)]++;
            }
            maxp = max(maxp, duplicate); 
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp)
                    maxp = slope.second + duplicate;
        } 
        return maxp;
    }
private:
    int gcd(int num1, int num2) {
        while (num2) {
            int temp = num2; 
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
};
```
