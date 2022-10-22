class Solution {
public:
    int fillingBucket(int N, int mod = 1e8) {
        vector<int> cache(N + 1, 0);
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                cache[i] = 1;
            } else {
                cache[i] = (cache[i] + cache[i - 1]) % mod;
                if (i > 1) {
                    cache[i] = (cache[i] + cache[i - 2]) % mod;
                }
            }
        }

        return cache[N];
    }
};