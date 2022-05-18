[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/search-a-2d-matrix/)


<details><summary>Hints</summary>

* Think the matrix as a 1-D array. <br>
* During binary-search, how can you represent the mid as a cell of the matrix? <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(logN)`, SC = `O(1)`

* We imagine the matrix as a 1-D array. <br>
* Preform binary-search with low set as `0` and high set as `n * m - 1`. <br>
* To find out which cell represents the mid, we can represent mid as row number `mid / m` and column number `mid % m`. <br>
* The rest is simple binary search. <br>
* If the mid represents the target, we return true, else we adjust the high or low depending on the value of mid and target and continue our search. <br>

</details>


Runtime: `3 ms`, faster than `88.40%`<br>
Memory Usage: `9.5 MB`, less than `53.61%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/74.png)

</details>