#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

bool check(char c) {
	return c == 'Y' or c == 'e' or c == 's';
}

void solve() {

	string s; cin >> s;
	int n = s.size();
	if (!check(s[0])) {
		cout << "NO" << '\n';
		return;
	}

	for (int i = 1; i < n; i++) {
		if (!check(s[i])) {
			cout << "NO" << '\n';
			return;
		}
		if (s[i] == 'Y' and s[i - 1] == 's') continue;
		if (s[i] == 'e' and s[i - 1] == 'Y') continue;
		if (s[i] == 's' and s[i - 1] == 'e') continue;
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}