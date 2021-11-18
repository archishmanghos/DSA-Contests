int orangesRotting(vector<vector<int>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    while(1)
    {
        int newlyRotten = 0;
        int grid2[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                grid2[i][j] = grid[i][j];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    if(i + 1 < n && grid[i + 1][j] == 1)
                    {
                        newlyRotten += 1;
                        grid2[i + 1][j] = 2;
                    }
                    if(j + 1 < m && grid[i][j + 1] == 1)
                    {
                        newlyRotten += 1;
                        grid2[i][j + 1] = 2;
                    }
                    if(i - 1 >= 0 && grid[i - 1][j] == 1)
                    {
                        newlyRotten += 1;
                        grid2[i - 1][j] = 2;
                    }
                    if(j - 1 >= 0 && grid[i][j - 1] == 1)
                    {
                        newlyRotten += 1;
                        grid2[i][j - 1] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                grid[i][j] = grid2[i][j];
        if(newlyRotten > 0)
            ans += 1;
        else
            break;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
                return -1;
        }
    }
    return ans;
}