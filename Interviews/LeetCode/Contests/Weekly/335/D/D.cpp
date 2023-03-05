#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int cache[55][1005];
	int dp(int idx, int target, vector<vector<int>>& types) {
		if (target == 0) return 1;
		if (idx == types.size()) return 0;
		if (cache[idx][target] != -1) return cache[idx][target];
		long answer = 0, MOD = 1e9 + 7;
		for (int i = 0; i <= types[idx][0]; i++) {
			if (target - i * types[idx][1] >= 0) {
				answer = (answer + 0ll + dp(idx + 1, target - i * types[idx][1], types)) % MOD;
			}
		}

		return cache[idx][target] = answer;
	}
	int waysToReachTarget(int target, vector<vector<int>>& types) {
		memset(cache, -1, sizeof(cache));
		return dp(0, target, types);
	}
};