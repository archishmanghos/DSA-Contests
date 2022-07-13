[Link to problem on Leetcode](https://leetcode.com/problems/binary-tree-level-order-traversal/)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(Max Width of Tree)`

- We take a queue of Nodes and push the given root to it. <br>
- At each step, we loop over the size of the queue and add the elements of the queue to the current level of the vector. <br>
- And at each step, we push the children of the current node (if exists) to our queue. <br>
- We continue this till the queue becomes empty. <br>


Runtime: `10 ms`, faster than `26.88%`<br>
Memory Usage: `12.4 MB`, less than `96.02%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/102.png)

</details>

</details>