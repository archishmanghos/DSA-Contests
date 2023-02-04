#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs (int r, int c, int mapr, int mapc, vector<int> &v, vector<bool> &vis, vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		if (vis[r * m + c]) return;
		vis[r * m + c] = true;

		v.push_back(mapr * m + mapc);
		int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

		auto check = [&](int x, int y) {
			return (x >= 0 and x < n and y >= 0 and y < m);
		};

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			int npr = mapr + dx[i], npc = mapc + dy[i];
			if (check (nr, nc) and grid[nr][nc] == 1) {
				dfs (nr, nc, npr, npc, v, vis, grid);
			}
		}
	}
	int countDistinctIslands(vector<vector<int>>& grid) {
		set<vector<int>> answer;
		int n = grid.size(), m = grid[0].size();
		vector<bool> visited(n * m, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i * m + j] and grid[i][j] == 1) {
					vector<int> v;
					dfs (i, j, 0, 0, v, visited, grid);
					answer.insert(v);
				}
			}
		}

		return answer.size();
	}
};