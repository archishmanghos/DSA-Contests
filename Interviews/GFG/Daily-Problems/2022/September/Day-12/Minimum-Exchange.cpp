int MinimumExchange(vector<vector<char>>matrix) {
    int ans1 = 0, ans2 = 0, n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                ans1 += matrix[i][j] != 'A';
                ans2 += matrix[i][j] != 'B';
            } else {
                ans1 += matrix[i][j] != 'B';
                ans2 += matrix[i][j] != 'A';
            }
        }
    }

    return min(ans1, ans2);
}