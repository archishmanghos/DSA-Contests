class Solution {
   public:
    int dp(int r, int c, int sum, int n, int m, int k, vector<vector<vector<int>>>& cache, vector<vector<int>>& grid) {
        if (r == n - 1 and c == m - 1) {
            return sum == 0;
        }

        int &ans = cache[r][c][sum], mod = 1e9 + 7;
        if (ans != -1)
            return ans;

        ans = 0;
        int dx[2] = {0, 1}, dy[2] = {1, 0};
        for (int i = 0; i < 2; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
                int nsum = (sum + grid[nr][nc]) % k;
                ans = (ans + dp(nr, nc, nsum, n, m, k, cache, grid)) % mod;
            }
        }

        return ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> cache(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return dp(0, 0, grid[0][0] % k, n, m, k, cache, grid);
    }
};