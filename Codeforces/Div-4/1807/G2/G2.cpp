#include <bits/stdc++.h>
#define int long long

void solve() {
	int N; std::cin >> N;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];
	std::sort(A, A + N);
	if (A[0] != 1) {
		std::cout << "NO" << '\n';
		return;
	}

	int curSum = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] <= curSum) {
			curSum += A[i];
		} else {
			std::cout << "NO" << '\n';
			return;
		}
	}

	std::cout << "YES" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}