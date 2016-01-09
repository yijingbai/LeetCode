#[BullsAndCows](https://leetcode.com/problems/bulls-and-cows/)
######No: `299`
######Tag: `HashMap`
######Difficulty: `Easy`

It is a easy question. But need to understand the rule. The rule is that
one secret could only match to one digit and can only use once. It means
if a secret digit is used as the cow and bull, it will never use again.
Therefore, we use a hashmap to store the show tme of the digit.
And when it is matched, minus the coressponding number.
