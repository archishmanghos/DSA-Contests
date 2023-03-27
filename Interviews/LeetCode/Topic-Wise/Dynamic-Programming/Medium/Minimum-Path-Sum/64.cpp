#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int cache[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cache[i][j] = 1e9;
			}
		}

		cache[0][0] = grid[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i - 1 >= 0) cache[i][j] = min(cache[i][j], cache[i - 1][j] + grid[i][j]);
				if (j - 1 >= 0) cache[i][j] = min (cache[i][j], cache[i][j - 1] + grid[i][j]);
			}
		}

		return cache[n - 1][m - 1];
	}
};