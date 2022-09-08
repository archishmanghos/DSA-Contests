[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/combination-sum-ii/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 ^ N * K)`, SC = `O(K * X)`, K is the average length of a subset and X is the number of combinations.

* This is the same logic as [Subsets II from Leetcode](https://leetcode.com/problems/subsets-ii/). You can read about my editorial from [here](https://github.com/archishmanghos/DSA-Contests/tree/master/Interviews/SDE-Sheet/Day-9-Recursion/Subsets-II). <br>
* The logic carried over is we have to sort the array and in each recursive call, we increase the size of the subset by 1. <br>
* We take care of duplicates by skipping them since duplicates will occur next to each other as the array has been sorted. <br>
* We push the subset to our answer if the target equals 0. <br>


Runtime: `16 ms`, faster than `25.84%`<br>
Memory Usage: `11.5 MB`, less than `29.89%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/40.png)

</details>

</details>