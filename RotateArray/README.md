## Rotate Array
For this problem, there is a simple and skill way: reverse the array for three time.
Taking the [1,2,3,4,5,6,7] and k = 3 as the example:

```
1. we reverse the array from n - k => 7 - 3 == 4 to n - 1 == 6
        +---+                +---+
        |   |                |   |
1 2 3 4 5 6 7   ==>  1 2 3 4 7 6 5

2. We reverse the array from 0 to n - k - 1 == 3
+-----+              +-----+
|     |              |     |
1 2 3 4 7 6 5   ==>  4 3 2 1 7 6 5

3. We reverse all of this array:
+-----------+        +-----------+
|           |        |           |
4 3 2 1 7 6 5   ==>  5 6 7 1 2 3 4

```

The we get the right result, and the space will be O(1) and time will be O(n).
