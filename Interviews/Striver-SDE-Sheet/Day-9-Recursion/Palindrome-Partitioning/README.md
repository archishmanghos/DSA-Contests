[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/palindrome-partitioning/)



<details><summary>Optimal Solution</summary>

Optimal Solution 2: TC ≈ `O((2 ^ N) * K * (N / 2))`, SC = `O(K * X)`

* We need to partition the string at every interval where the interval is a palindrome. <br>
* We need to do this recusively till we can't make any more partitions. <br>
* If the last partition we made is done on the last index, we put all the partitions in our answer vector. <br>


Runtime: `255 ms`, faster than `29.93%`<br>
Memory Usage: `140.7 MB`, less than `22.26%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/131.png)

</details>

</details>