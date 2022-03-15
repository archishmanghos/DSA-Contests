Optimal Solution: TC = `O(N)`, SC = `O(N)`

> We use a stack to keep track of valid parenthesis. <br>
> If we encounter a '(', we push the index of the bracket to the stack. <br>
> If we encounter a ')', we check if stack is non-empty, if it is, we pop 1 element from stack, else we mark that position in string with a '.'.<br>
> Finally, after coming out of the loop, we mark the indices of the stack in the string as '.'. <br>
> The answer string will be every character without the '.'.<br>

Runtime: `27 ms`, faster than `66.41%` <br>
Memory Usage: `11.7 MB`, less than `42.01%`