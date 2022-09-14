void shortest_distance(vector<vector<int>>&matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (matrix[j][i] > -1 and matrix[i][k] > -1) {
					if (matrix[j][k] == -1) {
						matrix[j][k] = matrix[j][i] + matrix[i][k];
					} else {
						matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
					}
				}
			}
		}
	}
}