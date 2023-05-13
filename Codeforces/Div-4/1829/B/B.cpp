#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int answer = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		if (A == 1) {
			answer = max(answer, cnt);
			cnt = 0;
		} else {
			++cnt;
		}
	}

	cout << max(answer, cnt) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}