My Solution: TC = `O(2xN)`, SC = `O(1)`

> We first calculate the length of the linkedlist using traversal.
> Next, we we calculate the position where we have to break, which is `(length - (k % length))`.
> Then we just break the linkedlist at that point, make the breakpoint node point to NULL and the rest point to head.

Runtime: `16 ms`, faster than `22.86%` <br>
Memory Usage: `11.8 MB`, less than `6.63%`