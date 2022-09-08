[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/clone-graph/)



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

* Create a copy of each node when it's visited and store a copy of it in hashmap.
* When an instance of a node is found in hashmap, push the mapped value.
* If an instance is not found, recursively make the new node.


Runtime: `4 ms`, faster than `91.61%`. <br>
Memory Usage: `8.9 MB`, less than `34.78%`.


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/133.png)

</details>

</details>