#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp (int r, int c, int mask, vector<int> &start, int boxes, vector<vector<int>>& grid) {
		if (r == start[0] and c == start[1]) {
			return mask == ((1 << boxes) - 1);
		}

		int ans = 0;
		int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (nr >= 0 and nr < grid.size() and nc >= 0 and nc < grid[0].size() and grid[nr][nc] != -1) {
				int pos = nr * grid[0].size() + nc;
				if (!((mask >> pos) & 1)) ans += dp (nr, nc, (mask | (1 << pos)), start, boxes, grid);
			}
		}

		return ans;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), boxes = 0;
		vector<int> start, end;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) start = {i, j};
				if (grid[i][j] == 2) end = {i, j};
				if (grid[i][j] != -1) boxes += 1;
			}
		}

		int pos = end[0] * m + end[1];
		return dp (end[0], end[1], (1 << pos), start, boxes , grid);
	}
};