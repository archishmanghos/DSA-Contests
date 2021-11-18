int orangesRotting(vector<vector<int>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
                q.push({i, j});
        }
    }

    while(!q.empty())
    {
        int nowSquares = q.size();
        bool squarePresent = false;
        while(nowSquares--)
        {
            pair<int, int> square = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                pair<int, int> adjacentSquare = {square.first + dx[i], square.second + dy[i]};
                if(adjacentSquare.first >= 0 && adjacentSquare.first < n)
                {
                    if(adjacentSquare.second >= 0 && adjacentSquare.second < m)
                    {
                        if(grid[adjacentSquare.first][adjacentSquare.second] == 1)
                        {
                            grid[adjacentSquare.first][adjacentSquare.second] = 2;
                            squarePresent = true;
                            q.push(adjacentSquare);
                        }
                    }
                }
            }
        }
        ans += squarePresent == true;
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