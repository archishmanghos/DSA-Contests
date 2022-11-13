class Solution {
   public:
    int totalWays(int n, vector<int> capacity) {
        sort(capacity.begin(), capacity.end());
        int k = 0, mod = 1e9 + 7;
        long ans = 1;
        for (auto it : capacity) {
            it -= k;
            k += 1;
            ans = (ans * it) % mod;
        }
        return ans;
    }
};