#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int distance[n * m];
		memset (distance, -1, sizeof(distance));

		queue<vector<int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) q.push({i, j});
			}
		}

		int dist = 1;
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				auto it = q.front(); q.pop();
				int r = it[0], c = it[1];

				auto valid = [&](int x, int y) {
					return (x >= 0 and x < n and y >= 0 and y < m);
				};

				int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
				for (int i = 0; i < 4; i++) {
					int nr = r + dx[i], nc = c + dy[i];
					if (!valid (nr, nc) or grid[nr][nc] == 1) continue;
					if (distance[nr * m + nc] == -1 or distance[nr * m + nc] > dist) {
						distance[nr * m + nc] = dist;
						q.push({nr, nc});
					}
				}
			}
			dist++;
		}

		int answer = -1;
		for (int i = 0; i < n * m; i++) {
			if (distance[i] != -1) answer = max (answer, distance[i]);
		}

		return answer;
	}
};