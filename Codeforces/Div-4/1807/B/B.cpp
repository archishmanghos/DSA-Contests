#include <bits/stdc++.h>
#define int long long

void solve() {
	int N; std::cin >> N;
	int even = 0, odd = 0;
	for (int i = 0; i < N; i++) {
		int A; std::cin >> A;
		if (A & 1) odd += A;
		else even += A;
	}

	std::cout << (even > odd ? "YES" : "NO") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}