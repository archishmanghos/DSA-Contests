Optimal Solution: TC = `O(logN)`, SC = `O(1)`

> We start by trying to reduce the target to the given number. <br>
> If the target is greater than the number, we should decrease it by dividing by 2. <br>
>> If the target is odd, we increase the target by 1 and the answer by 1 before dividing. <br>
>> If the target is even, we just divide it by 2. <br>
> If the target becomes less than the given number, we add the difference of the 2 and break out of our loop. <br>

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `5.9 MB`, less than `29.71%`