#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int cache[505][505][66][2];

int dp(int x, int y, int mask, int curDir, int N, int E, vector<vector<int>> &flowers) {
	if (cache[x][y][mask][curDir] != -1) {
		return cache[x][y][mask][curDir];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!((mask >> i) & 1)) {
			if (flowers[i][1] <= y) {
				mask ^= (1 << i);
				if (flowers[i][0] == x) {
					ans = max(ans, dp(flowers[i][0], flowers[i][1], mask, curDir, N, E, flowers) + flowers[i][2]);
				} else if (flowers[i][0] < x) {
					if (curDir) {
						ans = max(ans, dp(flowers[i][0], flowers[i][1], mask, 0, N, E, flowers) + (flowers[i][2] - E));
					} else {
						ans = max(ans, dp(flowers[i][0], flowers[i][1], mask, 0, N, E, flowers) + flowers[i][2]);
					}
				} else {
					if (curDir) {
						ans = max(ans, dp(flowers[i][0], flowers[i][1], mask, 1, N, E, flowers) + flowers[i][2]);
					} else {
						ans = max(ans, dp(flowers[i][0], flowers[i][1], mask, 1, N, E, flowers) + (flowers[i][2] - E));
					}
				}
				mask ^= (1 << i);
			}
		}
	}

	return cache[x][y][mask][curDir] = ans;
}

void solve() {
	int N, E; cin >> N >> E;
	vector<vector<int>> flowers(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> flowers[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(flowers[i][0], flowers[i][1], (1 << i), 1, N, E, flowers) + flowers[i][2]);
	}

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