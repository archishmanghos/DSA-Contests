Optimal Solution: TC = `O(N)`, SC = `O(1)`

* Traverse the tree inorder wise.<br>
* Since, inorder traversal traverses nodes in increasing order, we keep a track of number of nodes traversed. <br>
* When the variable hits k, we return the function and store the value of root in our answer. <br>

Runtime: `23 ms`, faster than `59.43%`<br>
Memory Usage: `24.1 MB`, less than `87.81%`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/230.png)

</details>