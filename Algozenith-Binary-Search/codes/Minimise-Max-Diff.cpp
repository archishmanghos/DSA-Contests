#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	if (A[0] == A[N - 1]) {
		cout << 0 << '\n';
		return;
	}

	int low = 1, high = 1e9 + 7, answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto check = [&]() {
			int insertions = 0;
			for (int i = 1; i < N; i++) insertions += (A[i] - A[i - 1] - 1) / mid;
			return insertions <= K;
		};

		if (check()) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
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