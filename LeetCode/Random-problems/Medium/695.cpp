bool visited[55][55];
int area;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, vector<vector<int>> &grid, int &n, int &m)
{
    if(x < 0 || x >= n)
        return;
    if(y < 0 || y >= m)
        return;
    if(grid[x][y] == 0)
        return;
    if(visited[x][y])
        return;
    visited[x][y] = true;
    area += 1;
    for(int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i], grid, n, m);
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && grid[i][j])
            {
                area = 0;
                dfs(i, j, grid, n, m);
                ans = max(ans, area);
            }
        }
    }
    return ans;
}