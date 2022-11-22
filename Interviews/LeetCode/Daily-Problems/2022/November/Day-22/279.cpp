class Solution {
   public:
    int numSquares(int n) {
        int sq = (int)sqrt(n);
        vector<int> cache(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cache[i] = 1e9;
            for (int j = 1; j <= sq; j++) {
                if (j * j <= i) {
                    cache[i] = min(cache[i], cache[i - j * j] + 1);
                }
            }
        }

        return cache[n];
    }
};