#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	if (N == 1) cout << 1 << '\n';
	else if (N & 1) cout << -1 << '\n';
	else {
		for (int i = N, j = 1; j < N; i -= 2, j += 2) cout << i << ' ' << j << ' ';
		cout << '\n';
	}
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}