[Link to problem on Leetcode](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(H) `

- We can use the idea of problem [173 Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) to avoid O(N) space. 
- The idea is that inorder traversal results in sorted array and hence the minimum difference will always be between 2 adjacent elements of the in-order traversal of the BST. 
- Hence, we use the BST iterator's next() property and check for difference between every adjacent nodes. 


Runtime: `8 ms`, faster than `20.75%`<br>
Memory Usage: `9.6 MB`, less than `99.16%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/783.png)

</details>

</details>