void setZeroes(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    bool mark1Cell0 = false;
    
    for(int i = 0; i < n; i++){
        if(!matrix[i][0]){
            mark1Cell0 = true;
        }
        for(int j = 1; j < m; j++){
            if(!matrix[i][j]){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 1; j--){
            matrix[i][j] = (!matrix[i][0] or !matrix[0][j] ? 0 : matrix[i][j]);
        }
        matrix[i][0] = (mark1Cell0 ? 0 : matrix[i][0]);
    }
}