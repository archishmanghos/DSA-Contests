class Solution {
public:
    int dfs(int curCellX, int curCellY, int &n, int &m, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &cache){
        if(curCellX == n - 1) return 0;
        if(cache[curCellX][curCellY] != -1) return cache[curCellX][curCellY];

        int ans = dfs(curCellX + 1, 0, n, m, grid, moveCost, cache) + moveCost[grid[curCellX][curCellY]][0] + grid[curCellX + 1][0];
        for(int i = 1; i < m; i++) ans = min(ans, dfs(curCellX + 1, i, n, m, grid, moveCost, cache) + moveCost[grid[curCellX][curCellY]][i] + grid[curCellX + 1][i]);

        return cache[curCellX][curCellY] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cache(n, vector<int>(m, -1));
        int ans = dfs(0, 0, n, m, grid, moveCost, cache) + grid[0][0];
        for(int i = 1; i < m; i++) ans = min(ans, dfs(0, i, n, m, grid, moveCost, cache) + grid[0][i]);

        return ans;
    }
};