[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/pascals-triangle/)


<details><summary>Hints</summary>

* Implement what is given in the problem. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N x N)`, SC = `O(1)`

* Initialise a 2-D matrix of size `numRows` <br>
* Start a loop from 0 to numRows and a nested loop from 0 to `value of 1st loop`. <br>
* Inside the nested loop, check if both i and j is greater than 0 or not. This will ensure that we are not on the edges of the triangle. <br>
* Next check if the previous row of the triangle has a size greater than the current value of j. This step is done since we have to sum `matrix[i - 1][j - 1]` and `matrix[i - 1][j]`. If The size is greater than j, it will ensure, `matrix[i - 1][j]` exists. <br>
* The next step is simple, we add the 2 values. <br>
* If the above conditions doesn't meet, we initialise with 1 instead. <br>

</details>

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `6.6 MB`, less than `33.76%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/118.png)

</details>