int numRollsToTarget(int n, int k, int target, int mod = 1e9 + 7) {
    vector<vector<long>> cache(n + 1, vector<long> (target + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (i == 0) {
                cache[i][j] = j == 0;
            } else {
                for (int l = 1; l <= k; l++) {
                    if (l <= j) {
                        cache[i][j] = (cache[i][j] + cache[i - 1][j - l]) % mod;
                    }
                }
            }
        }
    }

    return int(cache[n][target]);
}