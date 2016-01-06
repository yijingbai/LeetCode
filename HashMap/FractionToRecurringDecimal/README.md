#[FractionToRecurringDecimal](https://leetcode.com/problems/fraction-to-recurring-decimal/)
######No: `166`
######Tag: `HashMap`
######Difficulty: `Medium`
I did not finished this problem by myself.

The main idea is that to mock the divide process. And the most important problem to solve is is identify the recurring parts.
Cited From https://leetcode.com/discuss/42159/0ms-c-solution-with-detailed-explanations , it has very good explanation.

```
Well, the key to this problem is on how to identify the recurring parts. After doing some examples using pen and paper, you may find that for the decimal parts to recur, the remainders should recur. So we need to maintain the remainders we have seen. Once we see a repeated remainder, we know that we have reached the end of the recurring parts and should enclose it with a ). However, we still need to insert the ( to the correct position. So we maintain a mapping from each remainder to the position of the corresponding quotient digit of it in the recurring parts. Then we use this mapping to retrieve the starting position of the recurring parts.

Now we have solved the trickiest part of this problem.

There are some remaining problems to solve to achieve a bug-free solution.

Pay attention to the sign of the result;
Handle cases that may cause overflow like numerator = -2147483648, denominator = -1 appropriately by using long long;
Handle all the cases of (1) no fractional part; (2) fractional part does not recur; and (3) fractional part recurs respectively.
To handle problem 3, we divide the division process into the integral part and the fractional part. For the fractional part, if it does not recur, then the remainder will become 0 at some point and we could return. If it does recur, the method metioned in the first paragraph has already handled it.
```
