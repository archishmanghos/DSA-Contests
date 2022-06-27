class Solution {
public:
    void dfs(int curCellx, int curCelly, int &n, int &m, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
        if (curCellx < 0 or curCellx >= n or curCelly < 0 or curCelly >= m)
            return;
        if (visited[curCellx][curCelly] or grid[curCellx][curCelly] == '0')
            return;
        visited[curCellx][curCelly] = true;
        dfs(curCellx + 1, curCelly, n, m, visited, grid);
        dfs(curCellx - 1, curCelly, n, m, visited, grid);
        dfs(curCellx, curCelly + 1, n, m, visited, grid);
        dfs(curCellx, curCelly - 1, n, m, visited, grid);
    }
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
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
};