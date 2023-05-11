#include <bits/stdc++.h>
using namespace std;

void solve() {
	int Y; cin >> Y;
	cout << max(1, (3 * Y)) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}