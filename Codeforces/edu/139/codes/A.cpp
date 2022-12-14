#include <bits/stdc++.h>
using namespace std;

vector<int> getdig(int n) {
	int cnt = 0, lastDig = 0;
	while (n > 0) {
		lastDig = n % 10;
		n /= 10;
		cnt += 1;
	}

	return {cnt, lastDig};
}

void solve() {
	int n; cin >> n;
	vector<int> a = getdig(n);

	int ans = (a[0] - 1) * 9 + a[1];
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}