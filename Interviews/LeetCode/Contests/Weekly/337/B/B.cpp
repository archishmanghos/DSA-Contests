#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkValidGrid(vector<vector<int>>& grid) {
		if (grid[0][0] != 0) return false;
		int n = grid.size();
		int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
		vector<int> start = {0, 0};
		int step = 0;
		while (step < n * n) {
			step++;
			bool ok = false;
			for (int i = 0; i < 8; i++) {
				int nr = start[0] + dx[i], nc = start[1] + dy[i];
				if (nr < 0 or nr >= n or nc < 0 or nc >= n) continue;
				if (grid[nr][nc] == step) {
					ok = true;
					start = {nr, nc};
					break;
				}
			}

			if (!ok and step < (n * n)) return false;
		}

		return true;
	}
};