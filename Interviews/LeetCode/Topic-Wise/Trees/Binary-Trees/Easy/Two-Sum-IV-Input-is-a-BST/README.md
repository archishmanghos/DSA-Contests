[Link to problem on Leetcode](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(H + H) `

- We can use the idea of problem [173 Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) to avoid O(N) space. 
- The idea is to use iterators left and right, which can be written as one iterator get(node, pushDir), where pushDir is direction of traverse. 
- Then we start with root, find next and previous elements in inorder traversal, which are the smallest and the biggest elements and use usual 2-sum logic with two pointers.

[Editorial Credits](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/1420743/Python-Solution-using-iterators-explained)


Runtime: `46 ms`, faster than `85.29%`<br>
Memory Usage: `36.2 MB`, less than `93.89%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/653.png)

</details>

</details>