## Search For a Range
For this question, initinally, I plan to just find the right value, and then
just loop to the left and right. But this have a problem that the worst case 
will cause the O(n) time. So the right way is to use binary Search to find 
the lowest bound and the highest bound. So we use two binary Search. For the 
lowest bound one, when target == nums[mid] we need to let right = mid and 
for the highest bound, left = mid. What's more, for the highest one, when
calculate the mid, it should be mid = (left + right + 1) / 2.
