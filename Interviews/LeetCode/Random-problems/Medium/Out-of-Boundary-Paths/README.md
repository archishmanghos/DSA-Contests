[Link to problem on Leetcode](https://leetcode.com/problems/out-of-boundary-paths/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(4 ^ N)`, SC = `O(1)`

- The naive idea would be to move in all the for directions(up,left,right,bottom) parallely, such that:

> 1. Moves are no longer left., or
> 2. We have crossed the boundary.
> So, this gives us the base condition for recursion.
>

- Now why this return 0 and return 1? ->

> Case 1: when we run out of moves and we have not exceeded the boundary, that means we have not found a way out of the grid, so return 0 in other words we are still inside the grid. <br>
> Case 2: We have exceeded the boundary, so return 1 saying that we have this one way to reach out of the boundary.
I hope it is clear till now.
>

- Move in all the four directions (up,left,right,down) decrementing the moves because when we go from the current state, to any of the four adjacent states, we have already used up a move.

- We return the sum of all the four paths because we want the total number of paths, that can exceed the boundary within the given moves.


This Method TLEs.



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(M * N * maxMoves)`, SC =  `O(M * N * maxMoves)`

- Can we memoize it? Yes as there are overlapping subproblems.
E.g.: Situations like [ i = 1, j = 1, max_moves = 1] will be calculated many times, e.g.: max_moves = 2 and coming left from i = 1, j = 2, or going right from i=1, j =0, or coming down from i = 0, j = 1 or going up from i = 2, j =1.

- So ,why to solve 4 times for the same [ i = 1, j = 1, max_moves = 1]. Better to memoize/store the computed result in some datastructure and return the result directly next time without actually computing [ i = 1, j = 1, max_moves = 1] again.

- I hope you understood why can/should we memoize!

- Now, use a dp array of shape [m * n * maxMove] as all the three factors are needed.
- At i = 1, j = 1 -> maxMove = 1 and maxMove = 2 will have different answers, so we need all the 3 values.

- Thus we create a 3D DP Array and each cell of the dp [i, j, x] array represents, the number of paths to move the ball out of the grid boundary form position [i, j] with max_moves = x.

Runtime: `6 ms`, faster than `91.62%`<br>
Memory Usage: `9.5 MB`, less than `38.46%`<br>

[Whole Editorial Credits](https://leetcode.com/problems/out-of-boundary-paths/discuss/1293697/Python%3A-Easy-to-Understand-Explanation%3A-Recursion-and-Memoization-with-time-and-space-complexity.)


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/576.png)

</details>

</details>