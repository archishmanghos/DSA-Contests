void dfs(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>>& grid) {
    if (i < 0 or j < 0 or i >= n or j >= m) return;
    if (grid[i][j] == '0' or visited[i][j]) return;
    visited[i][j] = true;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1 , 0, 0};
    for (int k = 0; k < 4; k++) {
        dfs(i + dx[k], j + dy[k], n, m, visited, grid);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' and !visited[i][j]) {
                ans += 1;
                dfs(i, j, n, m, visited, grid);
            }
        }
    }

    return ans;
}