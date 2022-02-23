Optimal Solution: TC = `O(V + E)`, SC = `O(V + E)`.

The most important part is we have to `Clone or make a deep copy of the graph`.
We can do this by `dfs or bfs`. We maintain a hashmap that maps from old node to the new node that checks if we have really made a copy or just reusing the old node. The rest is plain dfs.

Runtime: `7 ms`, faster than `73.16%`
Memory Usage: `8.8 MB`, less than `45.65%`