#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int cnt[2] = {0};
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		cnt[a % 2]++;
	}

	if (cnt[1] & 1) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}