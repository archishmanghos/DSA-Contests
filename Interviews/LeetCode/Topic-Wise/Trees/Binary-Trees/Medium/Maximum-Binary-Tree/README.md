My solution: TC = `O(N ^ 2)`, SC = `O(1)`

> We use a recursive approach to form the solution. <br>
> We pass on a range to the function and perform a preorder traversal. <br>
> We find the maximum element in the range and make a new node with value as the current root. <br>
> We then pass on the new range as `[l, pos - 1]` to the left child, and another range `[pos + 1, r]` to the right child, considering l and r as the original range co-ordinates. <br>
> Finally we return the root. <br>

Runtime: `124 ms`, faster than `52.04%` <br>
Memory Usage: `42.1 MB`, less than `72.60%`