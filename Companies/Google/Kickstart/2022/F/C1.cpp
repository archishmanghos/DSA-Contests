#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int dp(int daysRem, int n, vector<bool> vis, vector<vector<int>> &seed, map<pair<int, vector<bool>>, int> &cache) {
	if (cache.find({daysRem, vis}) != cache.end()) {
		return cache[ {daysRem, vis}];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (seed[i][1] < daysRem) {
				vis[i] = true;
				ans = max(ans, dp(daysRem - 1, n, vis, seed, cache) + seed[i][2]);
				vis[i] = false;
			}
		}
	}

	return cache[ {daysRem, vis}] = ans;
}

void solve() {
	int D, N, X; cin >> D >> N >> X;
	vector<vector<int>> seed(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		cin >> seed[i][0] >> seed[i][1] >> seed[i][2];
	}

	map<pair<int, vector<bool>>, int> cache;
	vector<bool> vis(N, false);
	int ans = dp(D, N, vis, seed, cache);

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}