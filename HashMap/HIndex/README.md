#[HIndex](https://leetcode.com/problems/h-index/)
######No: `274`
######Tag: `HashMap`
######Difficulty: `Medium`
I did not come up the solution by myself.

The idea is that, first, we know that the h-index >= 1 && h-index < citation.size(). 
And also, considering the definition of the h-index: h of N papers have at least h citations each.
We know that if the citations >= citation.size(), we just set at occursion times to ctation.size().
In the first iteration, we count the show times of each number. If it >= N, count it to N.
Then for the second iteration, we start from MAX possible value h. And sum the citation num.
if the citation num >= h, measn have at lest h citation each. Then we return h. 
If all the citation num < h, we just return the citenum at last.
