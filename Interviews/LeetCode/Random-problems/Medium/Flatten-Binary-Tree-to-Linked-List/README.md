<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(N)`, SC = `O(N)` 

- Perform recursion and reverse pre-order.
- After recursion calls end, attach prev node to root's right and assign NULL to root's left.
- Re-assign the prev node to the current root node.


Runtime: `7 ms`, faster than `81.17%`<br>
Memory Usage: `12.6 MB`, less than `78.06%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/114-A.png)

</details>

</details>



<!-- <details><summary>Optimal Solution</summary>

Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>


<details><summary>Clean Code</summary>

![]()

</details>

</details> -->