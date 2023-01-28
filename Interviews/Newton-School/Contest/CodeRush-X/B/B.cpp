#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, L, S;
	cin >> N >> L >> S;

	int sum = L * (L + 1) / 2;
	if (sum > S) {
		cout << "NO" << '\n';
		return;
	}

	int minn = L * (L + 1) / 2;
	int extra = N - L;
	int maxx = (N * (N + 1) / 2) - extra * (extra + 1) / 2;
	if (S >= minn and S <= maxx) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}