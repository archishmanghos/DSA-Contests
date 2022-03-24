Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

> We can use 2 pointers to find the answer greedily. <br>
> First, we need to sort the array. <br>
> Then we need to place a pointer at beginning and another at end. <br>
> If [people[i] + people[j] <= limit], it means we can effectively put both i-th and j-th persons on the same boat, hence we increase our answer by 1 and change both i and j. <br>
> Else, we need to put the j-th person in a separate boat and decrease j and increase our answer. <br>

Runtime: `64 ms`, faster than `98.84%`<br>
Memory Usage: `42 MB`, less than `57.42%`