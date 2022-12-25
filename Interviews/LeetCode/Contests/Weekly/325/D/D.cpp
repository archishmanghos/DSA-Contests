#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long cache[1005][1005];
	long long sub(long long a, long long b, int p = 1e9 + 7) {
		int c = a - b;
		if (c < 0)
			c += p;
		return c;
	}

	long long mul(long long a, long long b, int p = 1e9 + 7) {
		return (1ll * a * b) % p;
	}

	long long pow(long long a, long long b, int m) {
		long long ans = 1;
		while (b) {
			if (b & 1)
				ans = (ans * a) % m;
			b /= 2;
			a = (a * a) % m;
		}
		return ans;
	}
	long long dp(int idx, int k, long long tsum, int split, vector<int> &nums, int mod = 1e9 + 7) {
		if (k < 0) return 0;
		if (idx < 0) return k > 0;

		long long &ans = cache[idx][k];
		if (ans != -1) return ans;

		ans = (dp(idx - 1, k - nums[idx], tsum, split, nums) % mod) + (dp(idx - 1, k, tsum, split, nums) % mod);
		return ans % mod;
	}
	int countPartitions(vector<int>& nums, int k) {
		long long sum = 0;
		int n = nums.size();
		for (int i : nums) sum += i;
		if (sum < (2ll * k)) return 0;
		memset (cache, -1, sizeof(cache));
		long long mod = 1e9 + 7, power = pow(2, n, mod);
		long long ans = dp(n - 1, k, sum, k, nums);
		long long finalAns = sub(power, mul(2, ans));
		return (int)finalAns;
	}
};