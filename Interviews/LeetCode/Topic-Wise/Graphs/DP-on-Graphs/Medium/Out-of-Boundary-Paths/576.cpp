bool isNotValid(int x, int y, int m, int n) {
    return (x<0 or x >= m or y<0 or y >= n);
}

int dfs(int x, int y, int movesLeft, int &m, int &n, vector<vector<vector<int>>> &cache) {
    if (movesLeft < 0) return 0;
    if (isNotValid(x, y, m, n)) return 1;
    if (cache[x][y][movesLeft] != -1) return cache[x][y][movesLeft];

    long ans = 0;
    int MOD = 1e9 + 7, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        ans = (ans + (1LL * dfs(x + dx[i], y + dy[i], movesLeft - 1, m, n, cache)) % MOD) % MOD;
    }

    return cache[x][y][movesLeft] = ans;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> cache(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    return dfs(startRow, startColumn, maxMove, m, n, cache);
}