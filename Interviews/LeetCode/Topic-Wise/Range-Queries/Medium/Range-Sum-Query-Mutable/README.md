<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/range-sum-query-mutable/)



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

Optimal Solution: TC = `O(NlogN)`, SC = `O(N)` 

- Direct Application of Fenwick Tree.
- You can read about it [here on HackerEarth](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/) or [here on Youtube](https://www.youtube.com/watch?v=DPiY9wFxGIw).
- One can also apply Sqrt Decomposition or Segment Tree but it's likely an overkill and much more complicated to implement.


Runtime: `668 ms`, faster than `56.31%`<br>
Memory Usage: `150.6 MB`, less than `88.22%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/307.png)

</details>

</details>