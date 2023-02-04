#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	char c; cin >> c;
	string S = "codeforces";
	for (char ch : S) {
		if (ch == c) {
			cout << "YES" << '\n';
			return;
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