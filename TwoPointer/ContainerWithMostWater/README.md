#[ContainerWithMostWater](https://leetcode.com/problems/container-with-most-water/)
######No: `11`
######Tag: `TwoPointer`
######Difficulty: `Medium`

I did not solved this by myself. Cited from https://leetcode.com/discuss/41527/simple-and-fast-c-c-with-explanation
there is a great solution.
```
Start by evaluating the widest container, using the first and the last line. All other possible containers are less wide, so to hold more water, they need to be higher. Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height. Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.

C++

int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
```
