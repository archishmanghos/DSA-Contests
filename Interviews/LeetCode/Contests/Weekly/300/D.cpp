bool isValid(int x, int y, int n, int m){
	return (x >= 0 and x<n and y >= 0 and y < m);
}
int dfs(int x, int y, int &n, int &m, vector<vector<int>> &cache, vector<vector<int>> &grid, int mod = 1e9 + 7){
	if(cache[x][y] != -1) return cache[x][y];

	int ans = 0;
	if(isValid(x + 1, y, n, m) and grid[x + 1][y] > grid[x][y]) ans += (dfs(x + 1, y, n, m, cache, grid) + 1) % mod;
	if(isValid(x - 1, y, n, m) and grid[x - 1][y] > grid[x][y]) ans += (dfs(x - 1, y, n, m, cache, grid) + 1) % mod;
	if(isValid(x, y + 1, n, m) and grid[x][y + 1] > grid[x][y]) ans += (dfs(x, y + 1, n, m, cache, grid) + 1) % mod;
	if(isValid(x, y - 1, n, m) and grid[x][y - 1] > grid[x][y]) ans += (dfs(x, y - 1, n, m, cache, grid) + 1) % mod;
	return cache[x][y] = ans % mod;
}
int countPaths(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> cache(n, vector<int>(m, -1));

    int ans = n * m, mod = 1e9 + 7;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		ans = ((ans % mod) + (dfs(i, j, n, m, cache, grid)) % mod) % mod;
    	}
    }

    return ans;
}