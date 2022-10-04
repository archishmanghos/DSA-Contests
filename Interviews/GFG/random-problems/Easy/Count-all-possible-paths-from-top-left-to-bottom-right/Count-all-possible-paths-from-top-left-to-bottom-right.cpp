long long int numberOfPaths(int m, int n, int mod = 1e9 + 7) {
    vector<vector<int64_t>> cache(m + 1, vector<int64_t>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 and j == n - 1) {
                cache[i][j] = 1;
            } else {
                cache[i][j] = (cache[i][j] + cache[i + 1][j]) % mod;
                cache[i][j] = (cache[i][j] + cache[i][j + 1]) % mod;
            }
        }
    }

    return cache[0][0];
}