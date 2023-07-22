#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp(int n, int idx, vector<int> &possibleOptions, vector<vector<int>> &cache, int MOD = 1e9 + 7) {
		if (n == 0) return 1;
		if (idx == possibleOptions.size()) return 0;
		int &answer = cache[n][idx];
		if (answer != -1) return answer;

		answer = dp(n, idx + 1, possibleOptions, cache);
		if (possibleOptions[idx] <= n) answer = (0ll + answer % MOD + dp(n - possibleOptions[idx], idx + 1, possibleOptions, cache) % MOD) % MOD;

		return answer;
	}
	int numberOfWays(int n, int x) {
		vector<vector<int>> possibleOptions(6);
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 300; j++) {
				int x = 1, k = i;
				while (x * j <= 300) {
					x *= j;
					k--;
					if (!k) break;
				}

				if (k == 0) possibleOptions[i].push_back(x);
			}
		}

		vector<vector<int>> cache(n + 2, vector<int>(305, -1));
		int answer = dp(n, 0, possibleOptions[x], cache);
		return answer;
	}
};