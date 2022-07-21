<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/reverse-linked-list-ii/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(N + right - left + 1)`, SC = `O(right - left + 1)`

- Traverse the list and put all nodes starting from left and ending at right into a vector. Also keep note on where the reverse starts and where it ends.
- Iterate from the back of the vector and link nodes with the node where reverse starts and continue the chain till vector becomes empty.
- Join the last node with the node from where reverse ended.


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `7.6 MB`, less than `17.76%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/92.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>


<details><summary>Clean Code</summary>

![]()

</details>

</details>