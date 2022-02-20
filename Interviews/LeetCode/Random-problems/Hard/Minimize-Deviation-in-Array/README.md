Optimal Solution: TC = `O(N)`, SC = `O(N)`

> The crux of the idea is we can operate on an `odd number only once`. <br>
> We make all the odd numbers even and put everything into a `priority queue`. <br>
> We then pop the elements one by one and half them such that they lie close to the minimum value.<br>
> We continue this till the every number becomes odd and we will have our minimum.

Runtime: `241 ms`, faster than `72.85%`
Memory Usage: `71.3 MB`, less than `83.44%` 