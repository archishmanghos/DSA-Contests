Optimal Solution: TC = `O(7)`, SC = `O(1)`

> The solution has 2 parts:
>> The first part is we need to add to our answer `26 + (26 x 26) + (26 x 26 x 26) + ..  till N-1 terms`.<br>
>> The second part is we will traverse from `0 to N-1` and add `(position of alphabet x (26 ^ (N - i - 1)))`.<br>
> This will give the required answer.

Runtime: `0 ms`, faster than `100.00%` <br>
Memory Usage: `6 MB`, less than `67.10%`