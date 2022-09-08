bool searchMatrix(vector<vector<int>> &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n * m - 1;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        int row = mid / m, column = mid % m;
        
        if(matrix[row][column] == target) return true;
        else if(matrix[row][column] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return false;
}