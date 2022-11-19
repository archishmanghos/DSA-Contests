#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int H, W, n, h, w; cin >> H >> W >> n >> h >> w;
	vector<vector<int>> a(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> totCnt(n + 1, 0);

	int totUnique = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			totCnt[a[i][j]] += 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		totUnique += totCnt[i] > 0;
	}

	for (int i = 0; i <= (H - h); i++) {
		vector<int> cnt(n + 1, 0);
		for (int j = i; j < i + h; j++) {
			for (int k = 0; k < w; k++) {
				cnt[a[j][k]] += 1;
			}
		}
		for (int j = 0; j <= (W - w); j++) {
			int unique = totUnique;
			for (int k = 1; k <= n; k++) {
				unique -= totCnt[k] > 0 and cnt[k] == totCnt[k];
			}
			cout << unique << ' ';
			if (j + w < W) {
				for (int k = i; k < i + h; k++) {
					cnt[a[k][j]] -= 1;
					cnt[a[k][j + w]] += 1;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}