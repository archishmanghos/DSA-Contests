[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/permutation-sequence/)



<details><summary>Optimal Solution 1</summary>

Optimal Solution 2: TC = `O(min(K, N! - K + 1) * N)`, SC = `O(1)`

* This is the brute method, we pass 2 parameters, depending on which is less, K or (N! - K + 1). <br>
* If the latter is less, we cycle through permutations from backward direction, else vice versa. <br>
* We keep a counter, which when equals K, returns the current string. <br>


Runtime: `622 ms`, faster than `5.87%`<br>
Memory Usage: `66.2 MB`, less than `5.02%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/60-A.png)

</details>

</details>


<details><summary>Optimal Solution 2</summary>

Optimal Solution 2: TC = `O(N ^ 2)`, SC = `O(N + N)`

* Here we use some maths to reduce the complexity drastically. <br>
* For every position from [1 to N], we place numbers according to k dividing the search space in blocks. <br>
* For each position, the block number is given by [k / fact(N - i - 1)]. <br>
* We determine the block number and place the block numbered indexed integer in its space and reduce k by [k % fact(N - i - 1)]. We also deleted the integer from our vector which is being placed in this position. <br>
* We proceed with the above steps till there is only 1 integer in our vector. <br>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `6 MB`, less than `48.83%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/60-B.png)

</details>

</details>