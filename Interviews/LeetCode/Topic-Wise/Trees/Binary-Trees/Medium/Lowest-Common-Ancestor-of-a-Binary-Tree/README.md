<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

<!-- 

<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>

<details><summary>Clean Code</summary>

![]()

</details>
 -->
<!-- </details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

- Recursively traverse the tree. 
- On finding a node equal to either of the given 2 nodes, stop traversing and return the node.
- If the left and right subtree returns the 2 given nodes, return the current node.
- If either of left and right subtree returns a NON NULL node, return the NON NULL node, else return NULL NODE.


Runtime: `18 ms`, faster than `83.62%`<br>
Memory Usage: `14.3 MB`, less than `57.81%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/236.png)

</details>

</details>