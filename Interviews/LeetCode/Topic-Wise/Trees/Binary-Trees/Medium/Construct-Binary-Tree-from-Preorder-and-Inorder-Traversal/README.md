[Link to problem on Leetcode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(N)`

- Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.<br>
- Initialize an integer variable preStart to keep track of the element that will be used to construct the root.<br>
- Implement the recursion function construct which takes a range of inorder and returns the constructed binary tree:<br>

> - if the range is empty, return null.<br>
> - initialize the root with preorder[preStart] and then increment preStart. <br>
> - recursively use the left and right portions of inorder to construct the left and right subtrees. <br>
>

- Simply call the recursion function with the entire range of inorder<br>

[Editorial Credits](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/)


Runtime: `8 ms`, faster than `99.35%`<br>
Memory Usage: `26.4 MB`, less than `28.28%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/105.png)

</details>

</details>