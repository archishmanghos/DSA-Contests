[Link to the problem on Leetcode](https://leetcode.com/problems/making-a-large-island/)

My Solution: TC = `O(N x N)`, SC = `O(N x N)`

* Colour the islands using different colours using DFS. <br>
* Store the area of each island in it's corresponding colour in a vector. <br>
* Traverse through the grid, if a 0 exists, find how many islands are present around it of different colours. <br>
* All islands of different colours can be merged using this 0. Hence take the area of it. <br>
* Find the maximum area over all such merged areas. <br>
* This maximum area is our answer. <br>

Runtime: `580 ms`, faster than `80.93%`<br>
Memory Usage: `95.1 MB`, less than `93.17%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/827.png)

</details>