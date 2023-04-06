#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs (int r, int c, bool &ans, vector<vector<int>>& vis, vector<vector<int>>& grid) {
		if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) {
			ans = false;
			return;
		}
		if (vis[r][c] or grid[r][c] == 1) return;
		vis[r][c] = 1;

		int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
		for (int i = 0; i < 4; i++) dfs(r + dx[i], c + dy[i], ans, vis, grid);
	}

	int closedIsland(vector<vector<int>>& grid) {
		vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
		int answer = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0 and !vis[i][j]) {
					bool ans = true;
					dfs (i, j, ans, vis, grid);
					if (ans) answer++;
				}
			}
		}

		return answer;
	}
};