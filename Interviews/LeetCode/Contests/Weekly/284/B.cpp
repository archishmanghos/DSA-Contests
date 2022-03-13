int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig){
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int l = 1;
    for(auto i : artifacts){
        for(int j = i[0]; j <= i[2]; j++){
            for(int k = i[1]; k <= i[3]; k++){
                grid[j][k] = l;
            }
        }
        l += 1;
    }
    int total = l - 1;
    for(auto i : dig){
        grid[i[0]][i[1]] = -1;
    }
    
    set<int> colourRemains;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != -1){
                colourRemains.insert(grid[i][j]);
            }
        }
    }
    
    int ans = total - colourRemains.size();
    return ans;
}