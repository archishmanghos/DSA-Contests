Optimal Solution: TC = `O(N)`, SC = `O(N)`

> First, we check if the size of the string is even or not. <br>
> If not even, then definitely the ans is false since pairing is not possible for one of the brackets atleast. <br>
> We use a stack to keep the parentheses in order. <br>
> We traverse the string and if we encounter any opening brackets, we add it to the stack. <br>
> If we encounter a closing bracket, we check if the array is empty, then we return false, else we check if the top of the stack contains the corresponding opening bracket. <br>
> If it contains, we pop the stack and continue, else we return false since the order gets wrong. <br>
> Finally, if the stack size becomes 0, we return true, else false. <br>

Runtime: `0 ms`, faster than `100.00%` <br>
Memory Usage: `6.2 MB`, less than `96.29%`