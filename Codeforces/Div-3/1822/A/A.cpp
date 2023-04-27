#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, Q; cin >> N >> Q;
	int A[N], B[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int answer = 0, idx = -1;
	for (int i = 0; i < N; i++) {
		if (Q >= A[i] + i) {
			if (B[i] > answer) {
				answer = B[i];
				idx = i + 1;
			}
		}
	}

	cout << idx << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}