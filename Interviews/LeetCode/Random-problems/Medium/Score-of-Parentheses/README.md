Optimal Solution: TC = O(N), SC = O(N)

> We use a stack to maintain the depth of the scores. <br>
> When we encounter a '(', we increase the depth of the stack by adding 0. <br>
> When we encounter a ')', we combine the last 2 elements of the stack and push them into the stack. If the top element is 0, we combine 1 to the next, else we double the top and add to the next. <br>
> The topmost element of the stack is our final answer. <br>

Runtime: 0 ms, faster than 100.00%<br>
Memory Usage: 6.2 MB, less than 45.05%