int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<vector<int>>> cache(n, vector<vector<int>> (k + 1, vector<int>(2, 0)));

    for (int index = n - 1; index >= 0; index--) {
        for (int j = 0; j <= k; j++) {
            for (int ifBought = 1; ifBought >= 0; ifBought--) {
                if (j == 0) continue;
                if (index == n - 1) {
                    cache[index][j][ifBought] = ifBought ? prices[index] : 0;
                } else {
                    int ans = 0;
                    if (ifBought) {
                        ans = max(cache[index + 1][j - 1][0] + prices[index], cache[index + 1][j][1]);
                    } else {
                        ans = max(cache[index + 1][j][1] - prices[index], cache[index + 1][j][0]);
                    }
                    cache[index][j][ifBought] = ans;
                }
            }
        }
    }

    return cache[0][k][0];
}