class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int> (m, -1));
        q.push({0, 0, 0, k});

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                int r = q.front()[0], c = q.front()[1], stepsTaken = q.front()[2], stepsLeft = q.front()[3];
                q.pop();
                if (vis[r][c] != -1 and vis[r][c] >= stepsLeft) continue;
                vis[r][c] = stepsLeft;
                if (r == n - 1 and c == m - 1) {
                    return stepsTaken;
                }

                int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
                for (int j = 0; j < 4; j++) {
                    int nr = r + dx[j], nc = c + dy[j];
                    if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
                        if (grid[nr][nc] == 1) {
                            if (stepsLeft > 0) {
                                q.push({nr, nc, stepsTaken + 1, stepsLeft - 1});
                            }
                        } else {
                            q.push({nr, nc, stepsTaken + 1, stepsLeft});
                        }
                    }
                }
            }
        }

        return -1;
    }
};