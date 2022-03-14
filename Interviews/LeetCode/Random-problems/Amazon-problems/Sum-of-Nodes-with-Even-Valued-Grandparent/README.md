Optimal Solution: TC = `O(N)`, SC = `O(1)`

> We perform a plain dfs to find the answer. <br>
> We pass on parent as a parameter to the dfs. <br>
> If the parent is even, we add to our answer the left and right of our child node if they exist, else we continue. <br>

Runtime: `49 ms`, faster than `79.88%` <br>
Memory Usage: `41.5 MB`, less than `44.67%`