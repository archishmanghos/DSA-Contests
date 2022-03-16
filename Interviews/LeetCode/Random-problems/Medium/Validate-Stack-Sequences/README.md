My Solution: TC = `O(N)`, SC = `O(N)`

> We take a stack and a pointer for the [popped] array. <br>
> We add the [pushed] elements 1 by 1 till the top of the stack equals the current [popped] element. <br>
> We remove the top element and the [popped] pointer till the elements match. <br>
> We then move and push the next element and the process continues. <br>
> Finally, we check if the stack is empty or not. <br>

Runtime: `12 ms`, faster than `58.78%` <br>
Memory Usage: `15.4 MB`, less than `59.16%`