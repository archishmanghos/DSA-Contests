#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> cnt(n + 2, 0);
	set<int> all;
	for (int i = 0; i <= n + 1; i++) {
		all.insert(i);
	}

	for (int i = 0; i < m; i++) {
		all.erase(a[i]);
		cnt[a[i]] += 1;
	}

	int ans = (*all.begin());
	for (int i = m; i < n; i++) {
		cnt[a[i]] += 1;
		if (all.find(a[i]) != all.end()) {
			all.erase(a[i]);
		}
		cnt[a[i - m]] -= 1;
		if (cnt[a[i - m]] == 0) {
			all.insert(a[i - m]);
		}
		ans = min(ans, (*all.begin()));
	}

	cout << ans;
	return 0;
}