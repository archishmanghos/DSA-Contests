Optimal Solution: TC = O(N), SC = O(1)

> We use 2 pointers, slow and fast. <br>
> slow pointer moves 1 step at a time and fast pointer moves 2 step at a time. <br>
> If there is a cycle, there we will be a time when slow pointer and fast pointer both will point at the same location. <br>
> If there is no cycle, the fast pointer will reach the end faster. <br>

Runtime: `7 ms`, faster than `97.41%` <br>
Memory Usage: `8.1 MB`, less than `58.87%`