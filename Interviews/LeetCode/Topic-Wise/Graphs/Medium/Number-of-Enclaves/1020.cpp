#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numEnclaves(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), answer = 0;
		queue<vector<int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
					if (grid[i][j] == 1) q.push({i, j});
				}
				answer += grid[i][j] == 1;
			}
		}

		while (!q.empty()) {
			int r = q.front()[0], c = q.front()[1];
			q.pop();
			if (grid[r][c] == 0) continue;
			grid[r][c] = 0;
			answer -= 1;
			int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
			auto valid = [&](int r, int c) {
				return (r >= 0 and r < n and c >= 0 and c < m);
			};
			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i], nc = c + dy[i];
				if (valid (nr, nc) and grid[nr][nc] == 1) q.push({nr, nc});
			}
		}

		return answer;
	}
};