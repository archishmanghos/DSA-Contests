Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

> We sort the intervals using a custom comparator, which sorts according to start points in `non-decreasing` order, if the start points are different, else end points in `non-increasing` order.<br>
> The remaining thing is just to maintain an end variable and incrementing answer, when an endpoint exceeds the end value.

Runtime: `28 ms`, faster than `63.82%`
Memory Usage: `11.3 MB`, less than `89.47%`