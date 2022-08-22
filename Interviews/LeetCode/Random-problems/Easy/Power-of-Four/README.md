<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/power-of-four/)



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

Optimal Solution: TC = `O(log4(n))`, SC = `O(1)` 

- Find the log4 value of n.
- This can be done using formula to find log a to base b = loga/logb.
- Hence log4(n) = log2(n) / log2(4)
- Now, we have to check if the log4(n) value is integer or not.

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `6.2 MB`, less than `6.02%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/342.png)

</details>

</details>