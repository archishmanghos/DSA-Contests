[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/maximum-subarray/)


<details><summary>Hints</summary>

* Should we consider a sum when it becomes negative? <br>
* What should we do if the current sum becomes negative? <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* We start accumulating the elements in a variable and take the maximum of the accumulation at each step. <br>
* If the current sum becomes negative, it means that we no longer benefit from taking the negative sum and we make it 0 to start afresh with the new subarray. <br>
* This gives the maximum sum over all subarrays. <br>

</details>


Runtime: `126 ms`, faster than `70.33%`<br>
Memory Usage: `67.8 MB`, less than `12.34%`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/53.png)

</details>