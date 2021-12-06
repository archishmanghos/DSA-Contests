void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int &n, int &m)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return;
    if(visited[x][y])
        return;
    if(grid[x][y] == '0')
        return;
    visited[x][y] = true;
    dfs(x + 1, y, grid, visited, n, m);
    dfs(x, y + 1, grid, visited, n, m);
    dfs(x - 1, y, grid, visited, n, m);
    dfs(x, y - 1, grid, visited, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1' && !visited[i][j])
            {
                ans += 1;
                dfs(i, j, grid, visited, n, m);
            }
        }
    }
    return ans;
}