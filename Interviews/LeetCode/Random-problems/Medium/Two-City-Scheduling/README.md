Optimal Solution: TC = `O(N ^ 2)`, SC = `O(N ^ 2)`

> There is a greedy solution to it using sorting, but I could not get the intuition, so I went with dynamic programming as it was much more intuitive to me. <br>
> We take 2 parameters in our recursive function, the current index and the number of candidates allocated to city A. <br>
> We then check 2 conditions: <br>
>> If the number of candidates allocated to city A is less than our required value, which is (n/2), we have 2 conditions again: <br>
>>> If the number of indices we have left is greater than the number of candidates required to fill the remaining slots in city A, we can either place the index in city B or city A. <br>
>>> If the number of indices we have left is not greater than the number of candidates required to fill the remaining slots in city A, we can only place the index in city A. <br>
>> If the number of candidates allocated to city A is equal to our required value, which is (n/2), we can only place them in city B. <br>
> The minimum of all these conditions is our required answer. <br>

Runtime: `8 ms`, faster than `42.77%`<br>
Memory Usage: `8.9 MB`, less than `19.71%`