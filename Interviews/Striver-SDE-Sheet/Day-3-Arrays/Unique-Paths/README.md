[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/unique-paths/)


<details><summary>Hints</summary>

* Think recursively. <br>
* If you could come up with the recursive solution, think of how to reduce the redundant recursive calls. <br>
* Now think how you can eliminate the space complexity and probably come up with a linear timed algo. <br>

</details>


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC ≈ `Exponential`, SC = `O(1)` (Not considering recursive stack space) <br>

* Recursively check for all paths. <br>
* When we reach the end, return 1 else 0. <br>
* Add all of them. <br>
	

Runtime: This will not pass this problem's checker since N can be 100, and 2 ^ 100 is not valid. However will work for small constraints. <br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/62-A.png)

</details>

</details>


<details><summary>Sub-Optimal Solution 2 (Memoizing Sub-Optimal Solution 1)</summary>

Sub-Optimal Solution 2: TC = `O(N x M)`, SC = `O(N x M)`

* We will do the same solution as the above solution, however, since we were counting cells that we have already calculated before, we were repeating steps over and over. <br>
* In this solution, we will calculate for a cell only once, store th count for this cell and use it when we encounter this cell again by giving the stored solution. <br>
* This heavily reduces the redundancies and we reduce the runtime drastically from exponential to just O(N x M).<br>
* We do this by taking a 2D vector to store the solutions for each cell. In this way, when we encounter this cell again, we can just provide the answer in O(1) by looking up for this cell in the vector. <br>
* Rest of the solution is same from part 1. We only add memoization. <br>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `6.4 MB`, less than `44.78%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/62-B.png)

</details>

</details>


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(min(N - 1, M - 1))`, SC = `O(1)`

* This solution is based on combinatorics. <br>
* The distance of every path is (n + m - 2). This can be proved. We can move atmost 1 unit distance in each step. So, the distance required to move from start to end will always be (m - 1) steps to the right and (n - 1) steps to the bottom. Adding both we get, (n + m - 2). <br>
* Now we need to fill up (n + m - 2) slots. <br>
* There are 2 options, either we place (n - 1) bottoms or (m - 1) rights. We can choose either. <br>
* Hence, the answer is (n + m - 2) C (n - 1) or (n + m - 2) C (m - 1). <br>
* Combinatorics is hard to understand textually, so [here's the video](https://www.youtube.com/watch?v=t_f0nwwdg5o) for better understanding. <br> 


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `5.9 MB`, less than `91.10%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/62-C.png)

</details>

</details>