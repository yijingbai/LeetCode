## Maximum Product Subarray
This is a dynamic programming question. Alouth I do not fully understand yet.
If we define f(n) to be the Since for the product, there are two possible scenarios:

1. When the number is postive, we need to track
   f(k) = max(f(k - 1) * nums[k], nums[k], g(k - 1) * nums[k])
   In this formula, the g(k - 1) means the min product value before, since we not only
   need to track the postive number, if the num is min and current num is also negative,
   we will get the biggest value.
2. When the number is negative:
   g(k) = min(g(k - 1) * nums[k], nums[k], f(k - 1) * nums[k])
