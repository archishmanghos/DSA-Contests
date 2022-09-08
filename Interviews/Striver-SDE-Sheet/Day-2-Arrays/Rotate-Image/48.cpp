void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for(int i = 0; i < n; i++){
        int j1 = 0, j2 = n - 1;
        while(j1 < j2){
            swap(matrix[i][j1++], matrix[i][j2--]);
        }
    }
}