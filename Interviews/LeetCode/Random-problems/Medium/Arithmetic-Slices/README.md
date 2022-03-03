Optimal Solution: TC = `O(N)`, SC = `O(1)`

> We take 2 extra varibles, `countNow` and `curDiff` to keep track of the number of elements in our subsegment currently and the current `Arithmetic Difference` now. <br>
> When we encounter a new difference, we set the `count` to 0 and `curDiff` to current difference.<br>
> We add to our answer the count in each step of the traversal.

Runtime: `0 ms`, faster than `100.00%` <br>
Memory Usage: `7.4 MB`, less than `55.42%`