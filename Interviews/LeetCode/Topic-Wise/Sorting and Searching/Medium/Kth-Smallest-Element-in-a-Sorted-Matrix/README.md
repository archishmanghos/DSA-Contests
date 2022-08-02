<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(N * N)`, SC = `O(K)` 

- [Solution 1 of this discuss](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise)


Runtime: `45 ms`, faster than `69.61%`<br>
Memory Usage: `14.3 MB`, less than `33.33%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/378-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O((N + M) * log(max - min))`, SC = `O(1)`

- [Solution 3 of this discuss](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise)


Runtime: `31 ms`, faster than `93.99%`<br>
Memory Usage: `13.2 MB`, less than `77.54%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/378-B.png)

</details>

</details>