#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int CountWays(string str) {
		if (str[0] == '0') return 0;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] == '0' and str[i - 1] == '0') return 0;
		}
		int MOD = 1e9 + 7, n = str.size();
		int cache[10005];
		memset (cache, -1, (n + 2) * sizeof(int));

		auto dp = [&](int idx, auto && dp) {
			if (idx == str.size()) return 1;
			if (str[idx] == '0') return 0;
			if (cache[idx] != -1) return cache[idx];

			int64_t answer = dp (idx + 1, dp) % MOD;
			if (idx + 1 < str.size() and str[idx] <= '2') {
				if (str[idx] < '2') answer = (answer % MOD + dp (idx + 2, dp) % MOD) % MOD;
				else if (str[idx + 1] <= '6') answer = (answer % MOD + dp (idx + 2, dp) % MOD) % MOD;
			}

			return cache[idx] = int(answer);
		};

		return dp (0, dp);
	}
};