[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/)


<details><summary>Hints</summary>

* You only have to check for the minimum stock price.

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* Take a variable to store the minimum stock price till the i-th stock. <br>
* Take another variable to store the answer, initially initialised as 0. <br>
* For each iteration, take the maximum of the answer variable and difference between current element and the minimum stock price. <br>

</details>


Runtime: `151 ms`, faster than `69.41%`<br>
Memory Usage: `93.4 MB`, less than `53.72%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/121.png)

</details>