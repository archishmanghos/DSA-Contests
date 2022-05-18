Optimal Solution: TC = `O(N x N)`

We can use trie to insert the all the substrings starting from i = [0, n - 1], i = [1, n - 1], ... till i = [n - 1, n - 1].<br>
Whenever we need to create a new link indicates that this will not be a distinct substring and hence we increase our answer. <br>
Finally we return ans + 1, as we will need to count an empty string as well. <br>

Runtime: `158ms`