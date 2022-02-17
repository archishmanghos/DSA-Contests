Optimal Solution: TC = O(NlogN + N), SC = O(1)

We sort the intervals array, so that it is ensure that each start and end are in increasing order.
We take 2 pointers that keep track of start and end of an interval.
If an interval is merging, we increase the end pointer, else, we take [start, end] and push into our answer.