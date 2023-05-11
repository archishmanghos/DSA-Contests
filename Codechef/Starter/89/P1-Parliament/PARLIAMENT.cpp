#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, X; cin >> N >> X;
	cout << (X >= ((N + 1) / 2) ? "YES" : "NO") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}