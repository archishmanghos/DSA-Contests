[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/count-the-paths4332/1)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 ^ N)`, SC = `O(N)`

**Intuition**:
- The main idea is to traverse all whole graph from the source node and count the total number of paths which reach the destination.

**Implementation**
- Run a DFS(Depth First Search) from the source node and visit all the paths leading from the source. 
- Whenever we reach the destination increase the counter for the answer.

[Editorial Credits (Click on The Editorial Tab)](https://practice.geeksforgeeks.org/problems/count-the-paths4332/1#editorial)


Total Time Taken: `0.01/1.33`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Count-the-paths.png)

</details>

</details>