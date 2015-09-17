#[RotateImage](https://leetcode.com/problems/rotate-image/)
######No: `48`
######Tag: `Array`
######Difficulty: `Medium`
For this problem, initially, I think it is a Matrix transpose, but when I read
it carefully, it is not a Matrix transpose. The rotation and the transpose are
the different operation for the Array.
Then I do not know how to solve it.
In discussion, there is a simple and efficient solution. Just need to in place
exchange. But to come up with this is little tricky.To rotate a Array Inplace,
we need to define a = 0, b = n - 1; Then for every number between a,b, we define
i.
Then we do these operation:

```
swap(m[a][a + i], m[a + i][b])
swap(m[a][a + i], m[b][b - i])
swap(m[a][a + i], m[b - i][a])
```
These three swap is to swap the lefttop corner of the number with the right top,
right down, left down. Then we repeatedly do this, we will get our final result.
