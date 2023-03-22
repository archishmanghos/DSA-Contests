#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int X, L, R; cin >> X >> L >> R;
	for (int i = L; i + 2 <= R; i++) {
		for (int j = i + 1; j + 1 <= R; j++) {
			for (int k = j + 1; k <= R; k++) {
				if (i * j * k == X) {
					cout << i << ' ' << j << ' ' << k << '\n';
					return;
				}
			}
		}
	}

	cout << -1 << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}