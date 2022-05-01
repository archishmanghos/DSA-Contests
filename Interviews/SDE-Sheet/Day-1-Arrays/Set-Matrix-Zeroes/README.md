[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to Problem on Leetcode](https://leetcode.com/problems/set-matrix-zeroes/)

**Ask the interviewer the range of the matrix elements. If they are small, we can change the matrix values to some un-reachable value and make matrix elements 0 in constant space.** <br>

Optimal Solution: TC = `O(2 x (N x M))`, SC = `O(1)`

<details><summary>Hints</summary>

* Think about a `O(N + M)` solution. <br>
* If O(N + M) solution passes, think of optimising it by bringing in the dummy row and column inside the matrix. <br>
* Be careful of the where the 1st row and 1st column meet, because the meeting point's value can change both values of 1st row and 1st column. <br>

</details>



<details><summary>Full Solution</summary>

* Treat the 1st row and 1st column as the dummy rows and columns. <br>
* Maintain a flag variable. <br>
* Traverse the matrix and check for 0s. <br>
* If the matrix element is 0, change the corresponding cell in 1st row and column to 0, only if the cell doesn't lie in the 1st column. <br>
* If the cell lies in the 1st column, change the maintained bool flag to true.
* Traverse the matrix again. For every cell that doesn't lie in the 1st column, check if the corresponding row or column contains 0. If it does, change the cell to 0. <br>
* For cells in the 1st column, check if the flag variable is true or not. If true, change to 0.

</details>


Runtime: `14 ms`, faster than `79.92%`<br>
Memory Usage: `13.1 MB`, less than `82.66%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/73.png)

</details>