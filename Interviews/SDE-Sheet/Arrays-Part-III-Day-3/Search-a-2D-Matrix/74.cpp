bool searchMatrix(vector <vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    int low = 0, high = m * n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid / m][mid % m] == target) {
            return true;
        } else if (matrix[mid / m][mid % m] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}