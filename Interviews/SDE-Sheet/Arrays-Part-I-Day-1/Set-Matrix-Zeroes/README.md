brute, TC = O(N * M * (N + M)), SC = O(N*M)

The brute force is fairly normal, we just take a vector
and store the positions where the matrix has 0. We then iterate
over the matrix again, and whenever we find a zero, we traverse the row and column and make the cells in them 0 too.

better brute, TC = O(N * M + N * M), SC = O(N + M)

The brute method is bettered by taking 2 1-D arrays representing
a dummy row and a dummy column. Whenever, we encounter
a 0 in the cell, we update the i-th cell of the column matrix with 0
and the j-th cell of the row matrix with 0.
In the next traversal, we check if either of i and j of the row and column matrix are 0,
if found, we make the cell 0

most optimal, TC = O(N * M + N * M), SC = O(1)

This method is an optimisation of the previous method. We don't take the dummy arrays,
and instead make the 1st row and column the dummy matrices.
We assign a column variable to check if the lower column or the right row is making the [0,0] cell 0.
In that case, we modify the bool variable, such that the other cells don't get affected.
Take care to traverse the 2nd time backwards.