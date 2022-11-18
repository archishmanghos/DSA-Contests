#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {

	int n; cin >> n;
	vector<int> ans(n, -1);
	set<int> s;
	map<int, int> mp;
	for (int i = 0; i < (n / 2); i++) {
		cin >> ans[i * 2 + 1];
		mp[ans[i * 2 + 1]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (mp.find(i) == mp.end()) {
			s.insert(i);
		}
	}

	for (int i = n - 1; i >= 1; i -= 2) {
		auto it = s.lower_bound(ans[i]);
		if (it == s.begin()) {
			cout << -1 << '\n';
			return;
		}

		it--;
		int ele = *it;
		ans[i - 1] = ele;
		s.erase(ele);
	}

	if (s.size() != 0) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		s.insert(ans[i]);
	}

	if (s.size() != n) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}