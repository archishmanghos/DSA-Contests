class Solution {
public:
	long long int NoOfChicks (int n) {
		vector<long long int> dp(n, 1);
		long long int ans = 1;
		for (int i = 1; i < n; i++) {
			if (i >= 6) {
				ans -= dp[i - 6];
			}
			dp[i] = ans * 2;
			ans += ans * 2;
		}

		return ans;
	}
};