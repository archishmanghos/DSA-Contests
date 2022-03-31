Optimal Solution: TC = `O(N)`, SC = `O(N)`

We perform a basic dfs and store level of nodes in the graph in a vector of size 2, where 0 represents even and 1 represents odd level. <br>
We add to a level if there is a node at that level. <br>
After the dfs is over, we add the number of pairs due to even level and due to odd level. <br>

Total Time Taken: `1.1/3.4`