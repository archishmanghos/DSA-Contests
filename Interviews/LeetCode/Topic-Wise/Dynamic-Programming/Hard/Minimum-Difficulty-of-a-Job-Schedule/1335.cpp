class Solution {
public:
    int dp(int idx, int d, int maxWork, vector<int>& jd, vector<vector<vector<int>>> &cache) {
        if (idx == jd.size()) {
            if (d > 0) return 1e9;
            return maxWork;
        }
        if (cache[idx][d][maxWork] != -1) {
            return cache[idx][d][maxWork];
        }

        int ans = dp(idx + 1, d, max(maxWork, jd[idx]), jd, cache);
        if (d > 0) {
            ans = min(ans, dp(idx + 1, d - 1, jd[idx], jd, cache) + maxWork);
        }

        return cache[idx][d][maxWork] = ans;
    }
    int minDifficulty(vector<int>& jD, int d) {
        int n = (int)jD.size();
        vector<vector<vector<int>>> cache(n, vector<vector<int>> (d, vector<int>(1001, -1)));
        int ans = dp(1, d - 1, jD[0], jD, cache);
        return ans == 1e9 ? -1 : ans;
    }
};