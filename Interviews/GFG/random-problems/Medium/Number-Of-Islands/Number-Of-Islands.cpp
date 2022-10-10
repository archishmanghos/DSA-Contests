class Solution {
public:
    void dfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited) {
        if (r < 0 or r >= n or c < 0 or c >= m) return;
        if (grid[r][c] == 0 or visited[r][c]) return;
        visited[r][c] = 1;
        int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            dfs(r + dx[i], c + dy[i], n, m, grid, visited);
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int k = operators.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            int islands = 0, r = operators[i][0], c = operators[i][1];
            grid[r][c] = 1;
            vector<vector<int>> visited(n, vector<int> (m, 0));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (!visited[j][k] and grid[j][k] == 1) {
                        islands += 1;
                        dfs(j, k, n, m, grid, visited);
                    }
                }
            }
            ans[i] = islands;
        }

        return ans;
    }
};