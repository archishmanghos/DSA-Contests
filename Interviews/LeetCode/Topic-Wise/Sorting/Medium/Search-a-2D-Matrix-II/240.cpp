bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size(), row = 0, column = m - 1;
    while (row<n and column >= 0) {
        if (matrix[row][column] == target) return true;
        matrix[row][column] > target ? column -= 1 : row += 1;
    }

    return false;
}