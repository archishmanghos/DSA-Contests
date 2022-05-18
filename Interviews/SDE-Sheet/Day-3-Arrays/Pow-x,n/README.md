[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/powx-n/)


<details><summary>Hints</summary>

* Read [Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html). <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(logN)`, SC = `O(1)`

* We can perform Binary-Exponentiation on the number. <br>
* If the power is odd, we multiply the base to our answer and decrement the power by 1. <br>
* If the power is even, we multiple the base to itself and divide the power by 2. <br>
* Take care of the power, it can be out of range for integer. <br>

</details>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `5.8 MB`, less than `96.46%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/50.png)

</details>