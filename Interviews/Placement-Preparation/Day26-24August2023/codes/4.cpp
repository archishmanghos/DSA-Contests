#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}

	int sz = 0;
	for (int i = 0; i < n; i++) {
		int vertical = a[i];
		if (mp.find(i) != mp.end()) sz += mp[i];
		int horizontal = n - sz;
		if (vertical != horizontal) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}