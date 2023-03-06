#include <bits/stdc++.h>
#define int long long

// all same -> n!
// min should give min on every & with others
// n - 2! * 2 * count * (count - 1) / 2

const int MOD = 1e9 + 7;
int N, A[200200];

void solve() {
	std::cin >> N;
	for (int i = 1; i <= N; i++) std::cin >> A[i];

	std::sort(A + 1, A + N + 1);
	if (A[1] == A[N]) {
		int answer = 1;
		for (int i = 1; i <= N; i++) answer = (answer * i) % MOD;
		std::cout << answer << '\n';
		return;
	}

	if (N < 3) {
		std::cout << 0 << '\n';
		return;
	}

	int answer = 2, count = 1;
	for (int i = 2; i <= N; i++) {
		if ((A[1] & A[i]) != A[1]) {
			std::cout << 0 << '\n';
			return;
		}
		if (i <= N - 2) answer = (answer * i) % MOD;
		if (A[i] == A[1]) count++;
	}

	int mul = count * (count - 1) / 2;
	answer = (answer * mul) % MOD;
	std::cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}