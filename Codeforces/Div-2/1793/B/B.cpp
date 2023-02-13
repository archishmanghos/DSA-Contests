#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int X, Y; cin >> X >> Y;
	cout << (X - Y) * 2 << '\n';
	cout << X - 1 << ' ' << X << ' ';
	if (X - Y > 1) {
		for (int i = X - 1; i >= Y; i--) {
			cout << i << ' ';
		}
		for (int i = Y + 1; i < X - 1; i++) {
			cout << i << ' ';
		}
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