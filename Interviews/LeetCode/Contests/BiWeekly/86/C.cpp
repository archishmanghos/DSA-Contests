int fun(int row, vector<int> vis, int col, int n, int m, vector<vector<int>>& mat) {
	if (row == n) return 0;
	int newCols = 0;
	for (int i = 0; i < m; i++) {
		newCols += mat[row][i] == 1 and vis[i] == 0;
	}

	int ans = fun(row + 1, vis, col, n, m, mat);
	if (newCols <= col) {
		for (int i = 0; i < m; i++) {
			if (mat[row][i] == 1) vis[i] = 1;
		}
		ans = max(ans, fun(row + 1, vis, col - newCols, n, m, mat) + 1);
	}

	return ans;
}
int maximumRows(vector<vector<int>>& mat, int cols) {
	int n = mat.size(), m = mat[0].size();
	vector<int> vis(m, 0);
	return fun(0, vis, cols, n, m, mat);
}