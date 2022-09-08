[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/course-schedule/)



<!-- <details><summary>Optimal Solution 1</summary>

Optimal Solution 1: TC = `O(2 ^ N)`, SC = `O(2 ^ N)` (considering stack space of recursion)

* We recursively find out all the subset sums of the given array. <br>
* We design a recursive function where we take in the the index and the current sum as parameters. <br>
* At each function call, we can either take the current index's element in our sum parameter or ignore it. <br>
* This generates all the subset sums. We push the sum in the answer array when the index hits the last point. <br>
	

Total Time Taken: `0.12 / 1.3`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Subset-Sums-A.png)

</details>

</details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution 2: TC = `O(V + E)`, SC = `O(V)`

* This can be done using a variation of Kahn's algorithm.
* We know, topological sort can only be applied on an acyclic graph.
* So, if we cannot apply topo sort, then the graph contains a cycle.


Runtime: `57 ms`, faster than `13.22%`. <br>
Memory Usage: `13.9 MB`, less than `55.05%`.


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/207.png)

</details>

</details>