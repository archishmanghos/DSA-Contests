vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (vector<int> q : Queries) {
        int a1 = q[0], a2 = q[1], b1 = q[2] + 1, b2 = q[3] + 1;
        ans[a1][a2] += 1;
        if (b1 < n) {
            ans[b1][a2] -= 1;
        }
        if (b2 < n) {
            ans[a1][b2] -= 1;
        }
        if (b1 < n and b2 < n) {
            ans[b1][b2] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int left = j > 0 ? ans[i][j - 1] : 0;
            int up = i > 0 ? ans[i - 1][j] : 0;
            int diagonal = i > 0 and j > 0 ? ans[i - 1][j - 1] : 0;
            ans[i][j] = ans[i][j] + left + up - diagonal;
        }
    }

    return ans;
}