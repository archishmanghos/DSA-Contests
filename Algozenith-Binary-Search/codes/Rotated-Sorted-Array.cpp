#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int low = 0, high = N - 1, answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (A[mid] < A[0]) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << (answer == -1 ? 0 : answer) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}