Optimal Solution: TC = `O(N)`, SC = `O(1)`

> Notice, that inorder traversal of a BST gives a sorted array. <br>
> Since, we need the greater values, we need to perform a reverse inorder traversal. <br>
> The rest is simple, we take a sum variable and dump the node value to it after performing the right recursion. <br>
> We then change the node value to the sum value and perform the left recursion. <br>

Runtime: `3 ms`, faster than `64.44%` <br>
Memory Usage: `8.1 MB`, less than `56.06%`