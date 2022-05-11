[Link to Problem on GFG](https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1/)


Optimal Solution: TC = `O(N)`, SC = `O(1)`

* We iterate `n` times and add to our string `min(9, sum)`, so that the string becomes larger. <br>
* If after `n` traversals, the sum is still greater than 0, it means it was greater than `9 x n` which is not possible, hence we return -1, else we return the formed string. <br>

Total Time Taken: `0.01 / 1.12`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Largest-number-with-given-sum.png)

</details>