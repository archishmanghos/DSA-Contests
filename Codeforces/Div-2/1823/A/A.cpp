#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			int x = (i * (i - 1) / 2) + (j * (j - 1) / 2);
			if (x == K) {
				if (i + j == N) {
					cout << "YES" << '\n';
					for (int k = 1; k <= i; k++) cout << 1 << ' ';
					for (int k = 1; k <= j; k++) cout << -1 << ' ';
					cout << '\n';
					return;
				}
			}
		}
	}

	cout << "NO" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}