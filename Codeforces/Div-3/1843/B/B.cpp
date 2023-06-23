#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int sum = 0, segments = 0, negative = false;
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) {
			if (!negative) ++segments;
			negative = true;
		}
		if (A[i] > 0) negative = false;
		sum += abs(A[i]);
	}

	cout << sum << ' ' << segments << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}