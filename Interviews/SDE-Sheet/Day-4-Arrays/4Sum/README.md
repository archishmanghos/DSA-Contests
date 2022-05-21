[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/4sum/)


<details><summary>Hints</summary>

* Try modifying the solution for 2-sum. <br>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC ≈ `O(N ^ 3)`, SC = `O(1)`

* We do the same solution as the 2-sum albeit with some differences. <br>
* The array is 1st sorted. <br>
* Then, we perform the 2 pointer approach on the last 2 elements of the 4 elements and the 1st 2 elements are taken using nested loops. <br>
* The number of redundant quadruples are eliminated by using a while loop by skipping consecutive equal elements in each loop. <br>


Runtime: `114 ms`, faster than `41.48%`<br>
Memory Usage: `13.2 MB`, less than `49.83%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/18.png)

</details>

</details>