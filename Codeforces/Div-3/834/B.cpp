#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {

	int m, s, a, maxx; cin >> m >> s;
	map<int, int> mp;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		maxx = max(maxx, a);
		mp[a] += 1;
	}

	for (int i = 1; i <= maxx; i++) {
		if (mp.find(i) == mp.end()) {
			s -= i;
		}
	}

	if (s < 0) {
		cout << "NO" << '\n';
		return;
	}

	int j = maxx + 1;
	while (s > 0) {
		s -= j;
		j += 1;
	}

	cout << (s == 0 ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}