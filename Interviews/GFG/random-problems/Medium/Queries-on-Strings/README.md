[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/queries-on-strings5636/1/)

Optimal Solution: TC = `O(26 x N + 26 x Q)`, SC = `O(26 x N)`

* Traverse the string, calculating the prefix sum for every character for every index in the string. Store the results in 2-D array. <br>
* Traverse the query vector and check for every character, if the difference of sums between L and R result in cnt > 0. If it does, we can increment our answer. <br>
* Return the final vector. <br>

Total Time Taken: `0.02 / 1.01`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Queries-on-Strings.png)

</details>