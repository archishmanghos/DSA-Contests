int cache[75][75][75];
int dp(int X, int Y1, int Y2, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if(X >= n || Y1 < 0 || Y1 >= m || Y2 < 0 || Y2 >= m)
        return 0;
    if(cache[X][Y1][Y2] != -1)
        return cache[X][Y1][Y2];
    int ans = 0;
    if(Y1 == Y2)
    {
        ans = max(dp(X + 1, Y1 - 1, Y2 - 1, grid), max(dp(X + 1, Y1 - 1, Y2, grid), max(dp(X + 1, Y1 - 1, Y2 + 1, grid), max(dp(X + 1, Y1, Y2 - 1, grid), max(dp(X + 1, Y1, Y2, grid), max(dp(X + 1, Y1, Y2 + 1, grid), max(dp(X + 1, Y1 + 1, Y2 - 1, grid), max(dp(X + 1, Y1 + 1, Y2, grid), dp(X + 1, Y1 + 1, Y2 + 1, grid))))))))) + grid[X][Y1];
    }
    else
    {
        ans = max(dp(X + 1, Y1 - 1, Y2 - 1, grid), max(dp(X + 1, Y1 - 1, Y2, grid), max(dp(X + 1, Y1 - 1, Y2 + 1, grid), max(dp(X + 1, Y1, Y2 - 1, grid), max(dp(X + 1, Y1, Y2, grid), max(dp(X + 1, Y1, Y2 + 1, grid), max(dp(X + 1, Y1 + 1, Y2 - 1, grid), max(dp(X + 1, Y1 + 1, Y2, grid), dp(X + 1, Y1 + 1, Y2 + 1, grid))))))))) + grid[X][Y1] + grid[X][Y2];
    }
    return cache[X][Y1][Y2] = ans;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    memset(cache, -1, sizeof(cache));
    return dp(0, 0, m - 1, grid);
}