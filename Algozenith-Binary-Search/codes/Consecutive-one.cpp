#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	int A[N], allzero = 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		allzero &= A[i] == 0;
	}

	if (allzero and K == 0) {
		cout << 0 << '\n';
		return;
	}

	int low = 1, high = N, answer = 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto check = [&]() {
			int zero = 0, i = 0, min_change = 1e9;
			for ( ; i < mid - 1; i++) zero += A[i] == 0;

			while (i < N) {
				zero += A[i++] == 0;
				min_change = min(min_change, zero);
				zero -= A[i - mid] == 0;
			}

			return min_change <= K;
		};

		if (check()) {
			answer = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}