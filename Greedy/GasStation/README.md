#[GasStation](https://leetcode.com/problems/gas-station/)
######No: `134`
######Tag: `Greedy`
######Difficulty: `Medium`
I did not finished this problem by myself. There are two approach:
```
I have thought for a long time and got two ideas:

If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must be a solution.
(Should I prove them?)
Here is my solution based on those ideas:

public int canCompleteCircuit(int[] gas, int[] cost) {
    int sumGas = 0;
    int sumCost = 0;
    int start = 0;
    int tank = 0;
    for (int i = 0; i < gas.length; i++) {
        sumGas += gas[i];
        sumCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if (sumGas < sumCost) {
        return -1;
    } else {
        return start;
    }
}
```
