#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int low = 1, high = accumulate(A, A + N, 0ll), answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto check = [&]() {
			int sum = 0, i = 0, painters = 1;
			while (i < N) {
				sum += A[i];
				if (sum > mid) {
					sum = A[i];
					if (sum > mid) return false;
					painters++;
				}
				i++;
			}

			return painters <= K;
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