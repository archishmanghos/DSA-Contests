int equalPairs(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<vector<int>> rows = grid, cols(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cols[i][j] = grid[j][i];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rows[i] == cols[j]) ans += 1;
		}
	}

	return ans;
}