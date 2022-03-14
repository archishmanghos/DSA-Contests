Optimal Solution: TC = `O(N ^ 2)`, SC = `O(1)`

> We first sort the array. <br>
> We set the last element as i from 2 to N-1.<br>
> We set the first element as j and the second element as i-1, named k. <br>
> We are using 2 pointer method here. <br>
> We check if `A[j] + A[k] > A[i]`, if it is we add (k-j) to our answer and decrease k, else we increase j. <br>

Runtime: `156 ms`, faster than `49.81%`<br>
Memory Usage: `12.9 MB`, less than `54.55%`