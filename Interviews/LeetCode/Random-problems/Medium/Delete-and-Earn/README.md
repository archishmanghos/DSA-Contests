My Solution: TC = `O(10000)`, SC = `O(2 x 10000)`

> The point from a single integer can be taken fully if we choose to erase that element. <br>
> Hence, we construct another vector, that stores the amount of points from a single integer. <br>
> Then we apply dp to find the maximum points attainable by iterating from 1 to 10^4. <br>

Runtime: `18 ms`, faster than `28.58%` <br>
Memory Usage: `14.8 MB`, less than `9.33%`