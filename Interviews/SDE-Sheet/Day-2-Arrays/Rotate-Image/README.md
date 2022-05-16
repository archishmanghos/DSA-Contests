[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/rotate-image/)


<details><summary>Hints</summary>

* Think about transpose of the matrix. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N x N)`, SC = `O(1)`

* Notice that reverse of the matrix is just transpose of the matrix with each row being reversed. <br>
* Find the transpose of the matrix by swapping the cells above the main diagonal with those below the main diagonal. <br>
* Reverse each row in a 2nd pass. <br>

</details>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `7.1 MB`, less than `34.42%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/48.png)

</details>