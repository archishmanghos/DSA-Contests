int uniquePaths(int m, int n) {
	swap(n, m);
	vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i == n - 1 and j == m - 1) cache[i][j] = 1;
			else {
				cache[i][j] = cache[i + 1][j] + cache[i][j + 1];
			}
		}
	}

	return cache[0][0];
}