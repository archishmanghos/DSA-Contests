#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K, A[200200], cache[200200][64][2];

int dp(int idx, int val, int taken, int MOD = 1e9 + 7) {
	if (idx == N) {
		if (!taken) return 0;
		return __builtin_popcount(val) == K;
	}

	if (cache[idx][val][taken] != -1) return cache[idx][val][taken];
	return cache[idx][val][taken] = (dp(idx + 1, val, taken) % MOD + dp(idx + 1, (!taken ? A[idx] : (val & A[idx])), 1) % MOD) % MOD;;
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 64; j++) {
			for (int k = 0; k <= 1; k++) {
				cache[i][j][k] = -1;
			}
		}
	}
	cout << dp(0, 0, 0) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}