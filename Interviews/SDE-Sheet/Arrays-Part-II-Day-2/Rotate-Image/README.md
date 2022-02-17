Brute Method: TC = O(N x N), SC = O(N x N)

In this method, we just take another 2-D matrix and do the following:

-> Take the first row and make it the last column of the new matrix.
-> Take the next row and make it the second-last column of the new matrix.
-> Continue this process, until we take the last row and make it the first column of the new matrix.

Optimal Method: TC = O(N x N), SC = O(1)

We can see, that the final matrix if nothing but the transpose of the original matrix,
but with all the rows reversed.

Hence, we transpose the given matrix and reverse each row.