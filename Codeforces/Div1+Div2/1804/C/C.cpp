#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, X, P; cin >> N >> X >> P;

	for (int i = 1; i <= min(P, 2 * N); i++) {
		int rotations = (i * (i + 1) / 2) % N;
		if (rotations == (N - X) % N) {
			cout << "Yes" << '\n';
			return;
		}
	}

	cout << "No" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}