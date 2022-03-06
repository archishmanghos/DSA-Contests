Optimal Solution: TC = `O(2 x N)`, SC = `O(1)`

> There are `(2N)!` possibilities. <br>
> Every pair is pre-defined since delivery can only occur after pickup. Hence we should remove `(2^N)` pairs in total. <br>
> Thus the final formula boils down to `(2N)!/(2^N)`. <br>
> Regarding the algorithm, we `don't need modular inverse`. We can apply a trick. <br>
> Notice, we have `(2 x 2 x 2 x ... N times)`. <br>
> In the numerator, we have `(1 x 2 x 3 x 4 x ... 2N times)`. <br>
> We have N even integers in the numerator. The N 2s in the denominator can cancel the N even integers in the numerator. <br>
> Hence we can loop from 1 to 2N and when i is even, we can just take i/2 and just `forget about the denominator`! <br>

Runtime: `0 ms`, faster than `100.00%` <br>
Memory Usage: `5.9 MB`, less than `53.14%`.