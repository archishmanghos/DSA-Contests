#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	vector<vector<int>> v;
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];

	int x = 0;
	for (int i = 0; i < N; i++) x += (abs(A[i] - (i + 1))) % K != 0;

	if (x) cout << (x == 2 ? 1 : -1) << '\n';
	else cout << 0 << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}