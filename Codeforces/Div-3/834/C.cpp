#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {

	int l, r, x, a, b; cin >> l >> r >> x >> a >> b;
	if (a == b) {
		cout << 0 << '\n';
		return;
	}
	if (abs(a - b) >= x) {
		cout << 1 << '\n';
		return;
	}
	if (abs(a - l) >= x and abs(l - b) >= x) {
		cout << 2 << '\n';
		return;
	}
	if (abs(a - r) >= x and abs(r - b) >= x) {
		cout << 2 << '\n';
		return;
	}
	if (abs(a - l) >= x and abs(l - r) >= x and abs(r - b) >= x) {
		cout << 3 << '\n';
		return;
	}
	if (abs(a - r) >= x and abs(l - r) >= x and abs(l - b) >= x) {
		cout << 3 << '\n';
		return;
	}
	cout << -1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}