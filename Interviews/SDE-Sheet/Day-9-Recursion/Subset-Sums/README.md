[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)



<details><summary>Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(2 ^ N)`, SC = `O(2 ^ N)` (considering stack space of recursion)

* We recursively find out all the subset sums of the given array. <br>
* We design a recursive function where we take in the the index and the current sum as parameters. <br>
* At each function call, we can either take the current index's element in our sum parameter or ignore it. <br>
* This generates all the subset sums. We push the sum in the answer array when the index hits the last point. <br>
	

Total Time Taken: `0.12 / 1.3`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Subset-Sums-A.png)

</details>

</details>



<details><summary>Optimal Solution 2</summary>

Optimal Solution: TC ≈ `O(2 ^ N)`, SC = `O(1)`

* This employs bit-manipulation technique. <br>
* We traverse over every number from `0 to 2 ^ N` and check for the set bits and calculate the sum of the elements of the set bits. <br>
* This is a well-known classical technique. <br>


Total Time Taken: `0.12 / 1.3` <br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Subset-Sums-B.png)

</details>

</details>