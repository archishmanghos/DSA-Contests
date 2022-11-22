class Solution {
   public:
    bool isPrime(int n) {
        return n == 2 or n == 3 or n == 5 or n == 7;
    }

    long dp(int idx, int k, bool atStart, int minLength, int n, string& s, vector<vector<vector<int>>>& cache) {
        if (idx > n)
            return 0;
        if (idx == n) {
            return k == 0;
        }
        if (k == 0)
            return 0;

        if (cache[idx][k][atStart] != -1) {
            return cache[idx][k][atStart];
        }

        long ans = 0, mod = 1e9 + 7;
        if (isPrime(s[idx] - '0')) {
            if (atStart) {
                ans = dp(idx + minLength - 1, k, 0, minLength, n, s, cache);
            } else {
                ans = dp(idx + 1, k, 0, minLength, n, s, cache);
            }
        } else {
            if (atStart) {
                return 0;
            } else {
                ans = (dp(idx + 1, k - 1, 1, minLength, n, s, cache) + dp(idx + 1, k, 0, minLength, n, s, cache)) % mod;
            }
        }

        return cache[idx][k][atStart] = ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();

        vector<vector<vector<int>>> cache(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return (int)dp(0, k, 1, minLength, n, s, cache);
    }
};