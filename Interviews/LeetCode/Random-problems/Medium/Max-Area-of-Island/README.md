[Link to problem on Leetcode](https://leetcode.com/problems/max-area-of-island/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N * M)`, SC = `O(N * M)`  

- So we can just use a simple iteration through the grid and look for islands. 
- When we find an island, we can use a recursive helper function (trav) to sum up all the connected pieces of land and return the total land mass of the island.
- As we traverse over the island, we can replace the 1s with 0s to prevent "finding" the same land twice. 
- We can also keep track of the largest island found so far (ans), and after the grid has been fully traversed, we can return ans.

[Editorial Credits](https://leetcode.com/problems/max-area-of-island/discuss/1244552/JS-Python-Java-C%2B%2B-or-Simple-DFS-Recursion-Solution-w-Explanation)


Runtime: `20 ms`, faster than `86.81%`<br>
Memory Usage: `23.6 MB`, less than `42.38%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/695.png)

</details>

</details>