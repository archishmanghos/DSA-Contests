#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	sort(A, A + N);
	int low = 1, high = A[N - 1] - A[0], answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto check = [&]() {
			int pre = A[0], i = 1, students = 1;
			while (i < N) {
				if (A[i] - pre >= mid) {
					students++;
					pre = A[i];
				}
				i++;
			}

			return students >= K;
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