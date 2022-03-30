Optimal Solution: TC = O(logN), SC = O(1)

We can consider the whole matrix as a linear sorted array. This is because we are told that the matrix is both column-wise sorted as well as row-wise sorted. <br>
Then, we can apply simple binary search over the whole matrix from [0, nm - 1], where n is the number of rows and m is the number of columns. <br>
We can access any matrix element using simple operators. Consider, we need to find what is the corresponding element of the matrix for index `j` of the sorted linear array. The row co-ordinate will be `j / m` and the column co-ordinate will be `j % m`. <br>
The rest is simple binary search. <br>

Runtime: 4 ms, faster than 77.73%<br>
Memory Usage: 9.6 MB, less than 5.69%<br>