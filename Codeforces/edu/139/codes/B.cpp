#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n;
	string s;
	cin >> n >> s;

	map<string, int> mp;
	for (int i = 0; i < n - 1; i++) {
		string t = s.substr(i, 2);
		if (mp.find(t) != mp.end()) {
			if (mp[t] + 1 < i) {
				cout << "YES" << '\n';
				return;
			}
		} else {
			mp[t] = i;
		}
	}

	cout << "NO" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}