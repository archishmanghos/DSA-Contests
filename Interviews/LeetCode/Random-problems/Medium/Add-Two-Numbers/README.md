My Solution: TC = `O(N)`, SC = `O(N)`

> We take a new linked list and just do the same as adding 2 numbers. <br>
> We take care of the carry in each step and finally at the last, we also check if there is a carry left, if left, we need to create a new node and that's it. <br>
> We can make the space O(1) using another loop that calculates the maximum length of the 2 lists. <br>
> We can then do an inplace addition of the numbers. <br>

Runtime: `28 ms`, faster than `90.59%` <br>
Memory Usage: `71.6 MB`, less than `11.57%`