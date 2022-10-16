class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        q.push({source.first, source.second});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        while (!q.empty()) {
            vector<int> cn = q.front();
            q.pop();

            int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int nr = cn[0] + dx[i], nc = cn[1] + dy[i];
                if (nr < 0 or nr >= n or nc < 0 or nc >= m or grid[nr][nc] != 1) {
                    continue;
                }
                if (dist[nr][nc] > dist[cn[0]][cn[1]] + 1) {
                    dist[nr][nc] = dist[cn[0]][cn[1]] + 1;
                    q.push({nr, nc});
                }
            }
        }

        if (dist[destination.first][destination.second] != 1e9) {
            return dist[destination.first][destination.second];
        }

        return -1;
    }
};