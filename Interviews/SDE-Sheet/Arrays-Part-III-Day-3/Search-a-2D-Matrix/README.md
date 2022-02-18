Solution which I came up with: TC = `O(N + logM)`, SC = `O(1)`

> We iterate over the rows and check if the target value is less than or equal to the last element of the row.
> We take that row and perform **`Binary Search`** over it to arrive at the target.

Optimal Solution: TC = `O(log(N x M))`, SC = `O(1)`

> The idea remains the same, we perform **`Binary Search`** over the whole matrix.
> We just have to tweak the `mid element` according to the value of `m`.

Runtime: `4 ms`, faster than `77.93%`
Memory Usage: `9.6 MB`, less than `52.18%`