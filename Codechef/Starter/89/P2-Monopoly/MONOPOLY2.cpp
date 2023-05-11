#include <bits/stdc++.h>
using namespace std;

void solve() {
	int A[4]; for (int i = 0; i < 4; i++) cin >> A[i];
	int sum = accumulate(A, A + 4, 0);

	for (int i = 0; i < 4; i++) {
		if (A[i] > (sum - A[i])) {
			cout << "YES" << '\n';
			return;
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