#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, Q; cin >> N >> Q;
	int pivot = N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (pivot == N and i > 0 and A[i] < A[i - 1]) pivot = i;
	}

	while (Q--) {
		int K; cin >> K;
		int low = 0, high = pivot - 1, answer = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (A[mid] == K) {
				answer = mid + 1;
				break;
			}
			if (A[mid] < K) low = mid + 1;
			else high = mid - 1;
		}

		if (answer != -1) cout << answer << ' ';
		low = pivot, high = N - 1, answer = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (A[mid] == K) {
				answer = mid + 1;
				break;
			}
			if (A[mid] > K) low = mid + 1;
			else high = mid - 1;
		}

		if (answer != -1) cout << answer;
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