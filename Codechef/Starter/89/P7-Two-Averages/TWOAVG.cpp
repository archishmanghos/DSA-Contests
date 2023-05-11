#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M, K; cin >> N >> M >> K;
	int S1 = 0, S2 = 0;
	for (int i = 0; i < N; i++) {
		int A; cin >> A; S1 += A;
	}

	for (int i = 0; i < M; i++) {
		int A; cin >> A; S2 += A;
	}

	int answer = 0;
	if ((S1 * M) > (S2 * N)) {
		cout << answer << '\n';
		return;
	}

	if (K == 1) {
		cout << -1 << '\n';
		return;
	}

	while ((S1 * M) <= (S2 * N)) {
		int netAdd1 = K * M - S2;
		int netAdd2 = S1 - N;

		if (netAdd1 >= netAdd2) {
			if (netAdd1 < 0) {
				cout << -1 << '\n';
				return;
			}

			S1 += K;
			++N;
			++answer;
		} else {
			if (netAdd2 < 0) {
				cout << -1 << '\n';
				return;
			}

			++S2;
			++M;
			++answer;
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