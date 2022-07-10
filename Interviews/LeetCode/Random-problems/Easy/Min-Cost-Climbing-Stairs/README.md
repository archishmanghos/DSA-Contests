[Link to problem on Leetcode](https://leetcode.com/problems/min-cost-climbing-stairs/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

1. All possibilities are considered via brute-force top-down depth-first-search
2. Remember each subproblems' optimal solution via a DP memo
3. Turn the top-down solution upside-down to create the bottom-up solution
4. Bottom-up memory optimization: instead of storing the entire dp array, we only need the last 2 values

[Editorial Credits](https://leetcode.com/problems/min-cost-climbing-stairs/discuss/110111/The-ART-of-dynamic-programming)


Runtime: `11 ms`, faster than `53.51%`<br>
Memory Usage: `13.6 MB`, less than `79.79%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/746.png)

</details>

</details>