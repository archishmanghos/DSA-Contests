#include <bits/stdc++.h>
using namespace std;

void solve() {
	int R, D; cin >> R >> D;
	cout << ((360 / D) % 2 == 0 ? "YES" : "NO") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}