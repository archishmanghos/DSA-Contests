Optimal Solution: TC = `O(N)`, SC = `O(N)`

This is a case-work implementation. <br>
For this we can consider a stack or vector (which will eventually behave like a stack) for our operations. <br>
We will have `4 cases` to consider while traversing the given vector: <br>
> If the string is `C`: In that case, we just pop the last element of the vector. <br>
> If the string is `D`: In that case, we add to our vector the double of the last element. <br>
> If the string is `+`: In that case, we add to our vector the sum of the previous 2 elements. <br>
> If the string is different than the above scenarios: In that case, we add to our vector the integer value of the given string. Make sure to pay attention if the string is negative or not. <br>
>
Finally we come out of the loop and return the sum of the vector elements. <br>

Runtime: `3 ms`, faster than `86.92%`<br>
Memory Usage: `8.3 MB`, less than `95.60%`
