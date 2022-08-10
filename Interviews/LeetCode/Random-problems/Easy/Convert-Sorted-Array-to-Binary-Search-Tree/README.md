<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)



<!-- <details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>

<details><summary>Clean Code</summary>

![]()

</details>

</details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)` 

- Take parameter as bounds of the current array.
- Take the mid of the bounds and make the current root the mid element of the array.
- Make the left child as [low, mid - 1] and right child as [mid + 1, high], where low and high are the current bounds.
- Continue till low <= high.


Runtime: `20 ms`, faster than `65.25%`<br>
Memory Usage: `21.5 MB`, less than `41.16%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/108.png)

</details>

</details>