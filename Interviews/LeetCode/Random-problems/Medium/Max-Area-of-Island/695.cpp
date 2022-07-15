bool isValid(int curX, int curY, int n, int m) {
    return (curX >= 0 and curX<n and curY >= 0 and curY < m);
}

void dfs(pair<int, int> curCell, int &area, int &n, int &m, vector<vector<bool>> &visited, vector<vector<int>>& grid) {
    int curX = curCell.first, curY = curCell.second;
    if (!isValid(curX, curY, n, m) or visited[curX][curY] or grid[curX][curY] == 0) return;

    visited[curX][curY] = true;
    area += 1;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        dfs({curX + dx[i], curY + dy[i]}, area, n, m, visited, grid);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 and !visited[i][j]) {
                int area = 0;
                dfs({i, j}, area, n, m, visited, grid);
                ans = max(ans, area);
            }
        }
    }

    return ans;
}