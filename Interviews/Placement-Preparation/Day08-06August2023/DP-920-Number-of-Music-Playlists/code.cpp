#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numMusicPlaylists(int n, int goal, int k) {
		int cache[goal + 1][n + 1], MOD = 1e9 + 7;
		memset(cache, -1, sizeof(cache));

		function<int(int, int)> dp = [&](int idx, int unique) {
			if (idx == 0 and unique == 0) return 1;
			if (idx == 0 or unique == 0) return 0;
			int &answer = cache[idx][unique];
			if (answer != -1) return answer;

			answer = (1ll * dp (idx - 1, unique - 1) * (n - unique + 1)) % MOD;
			if (unique > k) answer = (answer + 1ll * dp (idx - 1, unique) * (unique - k)) % MOD;

			return answer;
		};

		return dp (goal, n);
	}
};