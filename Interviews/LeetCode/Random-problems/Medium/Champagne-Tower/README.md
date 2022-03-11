Optimal Solution: TC = `O(R x R)`, SC = `O(R x R)`

> We take a 2D vector and start filling the squares in accordance to `Pascal's Triangle`.
> We initialise the (0,0) th square as n, the (1,0)th as (n-1)/2 and (1,1)th as (n-1)/2.<br> 
> The next row, we do (2,0) th as ((n-1)/2-1)/2 , (2,1)th as (((n-1)/2-1)/2) x 2, since this glass is being filled by 2 glasses and the (2,2)th as ((n-1)/2-1)/2 again.
> Simulating this, we get our final answer.

Runtime: `8 ms`, faster than `73.16%` <br>
Memory Usage: `14.6 MB`, less than `39.75%`