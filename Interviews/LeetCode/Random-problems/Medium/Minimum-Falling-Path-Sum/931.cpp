bool checkValid(int indexX, int indexY, int n){
    return (indexX >= 0 and indexX<n and indexY >= 0 and indexY < n);
}
int dfs(int indexX, int indexY, int &n, vector<vector<int>> &matrix, vector<vector<int>> &cache){
    if(!checkValid(indexX, indexY, n)){
        if(indexX >= n){
            return 0;
        }
        return 10000;
    }
    if(cache[indexX][indexY] != -1){
        return cache[indexX][indexY];
    }
    
    int ans = 10000, dx[3] = {1, 1, 1}, dy[3] = {0, -1, 1};
    for(int i = 0; i < 3; i++){
        ans = min(ans, dfs(indexX + dx[i], indexY + dy[i], n, matrix, cache) + matrix[indexX][indexY]);
    }
    return cache[indexX][indexY] = ans;
}
int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> cache(n, vector<int>(n, -1));
    int ans = 10000;
    for(int i = 0; i < n; i++){
        ans = min(ans, dfs(0, i, n, matrix, cache));
    }
    return ans;
}