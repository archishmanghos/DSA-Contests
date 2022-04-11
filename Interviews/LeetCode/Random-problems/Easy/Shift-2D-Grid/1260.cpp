vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ansGrid(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int curCell = i * m + j;
            int newCell = (curCell + k) % (n *m);
            ansGrid[newCell / m][newCell % m] = grid[i][j];
        }
    }
    
    return ansGrid;
}