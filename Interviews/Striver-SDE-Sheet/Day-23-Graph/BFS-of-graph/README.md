[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)



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

Optimal Solution 2: TC ≈ `O(N)`, SC = `O(N)`

* Use a queue and perform BFS.
* Store all nodes in order.


Total Time Taken: `0.03`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/BFS-of-graph.png)

</details>

</details>