#include <bits/stdc++.h>
using namespace std;

int N, M, A[205];

void solve() {
	cin >> N >> M;
	for (int i = 1; i < N + M; i++) cin >> A[i];

	int64_t answer;
	cin >> answer;
	sort(A + 1, A + N + M, greater<int>());
	for (int i = 1; i <= N - 1; i++) answer += A[i];

	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}