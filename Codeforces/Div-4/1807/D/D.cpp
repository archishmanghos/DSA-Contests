#include <bits/stdc++.h>
#define int long long

void solve() {
	int N, Q; std::cin >> N >> Q;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];
	int pref[N];
	pref[0] = A[0];
	for (int i = 1; i < N; i++) pref[i] = pref[i - 1] + A[i];

	int totSum = pref[N - 1];

	while (Q--) {
		int L, R, K; std::cin >> L >> R >> K;
		L--, R--;
		int changedSum = (R - L + 1) * K;
		int prevSum = pref[R] - (L > 0 ? pref[L - 1] : 0);
		if (totSum & 1) {
			if (prevSum & 1) {
				if (changedSum & 1) std::cout << "YES" << '\n';
				else std::cout << "NO" << '\n';
			} else {
				if (changedSum & 1) std::cout << "NO" << '\n';
				else std::cout << "YES" << '\n';
			}
		} else {
			if (prevSum & 1) {
				if (changedSum & 1) std::cout << "NO" << '\n';
				else std::cout << "YES" << '\n';
			} else {
				if (changedSum & 1) std::cout << "YES" << '\n';
				else std::cout << "NO" << '\n';
			}
		}
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