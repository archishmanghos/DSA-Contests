Optimal Solution: TC = `O(N)`, SC = `O(N)`

We take a stack initially. <br>
We traverse the string backwards and consider 2 cases. <br>
> If the i-th character is less than or equal to the [i + 1]th character or the stack is empty, we push the current character to the stack. <br>
> If it is not, we pop the stack such that the top of the stack is less than the current element. However, if there are multiple instances of the same character, that is less, we consider the first instance. <br>
>
After this, we check if there were no cases of the 2nd case described above. If there were none, we return -1. <br>
Else, we swap the 2 positions found and return the string. <br>

Total Time Taken: `0.0/1.0`