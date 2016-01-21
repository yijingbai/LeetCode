#[SudokuSolver](https://leetcode.com/problems/sudoku-solver/)
######No: `37`
######Tag: `HashMap`
######Difficulty: `Hard`

This problem need to do by backtrack. But if we have careful prune as well as
some optimization, we could have a faster backtracking solution.
Cited From https://leetcode.com/discuss/21452/sharing-my-2ms-c-solution-with-comments-and-explanations
```
This is one of the fastest Sudoku solvers I've ever written.
It is compact enough - just 150 lines of C++ code with comments.
 I thought it'd be interesting to share it, since it combines 
several techniques like reactive network update propagation and 
backtracking with very aggressive pruning.

The algorithm is online - it starts with an empty board and as
 you add numbers to it, it starts solving the Sudoku.

Unlike in other solutions where you have bitmasks of allowed/disallowed 
values per row/column/square, this solution track bitmask for 
every(!) cell, forming a set of constraints for the allowed values
 for each particular cell. Once a value is written into a cell, 
new constraints are immediately propagated to row, column and 
3x3 square of the cell. If during this process a value of other
 cell can be unambiguously deduced - then the value is set, new
 constraints are propagated, so on.... You can think about this
 as an implicit reactive network of cells.

If we're lucky (and we'll be lucky for 19 of 20 of Sudokus 
published in magazines) then Sudoku is solved at the end (or 
even before!) processing of the input.

Otherwise, there will be empty cells which have to be resolved. 
Algorithm uses backtracking for this purpose. To optimize it, 
algorithm starts with the cell with the smallest ambiguity. 
This could be improved even further by using priority queue 
(but it's not implemented here). Backtracking is more or less 
standard, however, at each step we guess the number, the reactive 
update propagation comes back into play and it either quickly 
proves that the guess is unfeasible or significantly prunes the 
remaining search space.

It's interesting to note, that in this case taking and restoring
 snapshots of the compact representation of the state is faster 
than doing backtracking rollback by "undoing the moves".
```
