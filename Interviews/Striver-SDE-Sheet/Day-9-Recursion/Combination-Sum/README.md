[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/combination-sum/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 ^ T * K)`, SC = `O(K * X)`, K is the average length of a subset and X is the number of combinations.

* In every recursive call, we repeatedly take the element of the current index till it exceeds the target. <br>
* If the target becomes 0, we push the subset to our answer. <br>


Runtime: `99 ms`, faster than `23.95%`<br>
Memory Usage: `39.1 MB`, less than `21.99%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/39.png)

</details>

</details>