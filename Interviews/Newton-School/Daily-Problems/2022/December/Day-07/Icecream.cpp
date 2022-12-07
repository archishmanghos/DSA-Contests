#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, a; cin >> n >> m;
	vector<int> cnt(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a;
			cnt[a] += 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += cnt[i] == n;
	}

	cout << ans;
	return 0;
}