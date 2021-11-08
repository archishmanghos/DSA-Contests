int islandPerimeter(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m)
                        ans += grid[x][y] == 0;
                    else
                        ans += 1;
                }
            }
        }
    }

    return ans;
}