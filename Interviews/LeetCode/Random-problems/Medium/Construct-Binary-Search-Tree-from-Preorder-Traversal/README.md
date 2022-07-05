[Link to problem on Leetcode ](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)` 

* We construct the same way we validate a BST from a BT. <br>
* We carry an upper bound which will determine if the current preorder elements suffices the condition that it should be less than the upper bound. <br>
* We check if the condition satisfies, if it does, we construct the left child by passing on the current node's value as the upper bound and the right child by passing the current node's upper bound value as the upper bound value. <br>
* Finally we return the root node. <br>


Runtime: `7 ms`, faster than `68.15%`<br>
Memory Usage: `13.6 MB`, less than `87.15%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1008.png)

</details>

</details>